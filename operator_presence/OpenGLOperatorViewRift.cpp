#include "stdafx.h"

#include "OpenGLOperatorViewRift.h"

#include "IOperatorViewMediator.h"
#include "IOperatorViewRenderer.h"

#include "scope_guard.h"

namespace operator_view
{
	namespace opengl
	{
		Rift::Rift(std::shared_ptr<IRenderer> renderer, std::shared_ptr<IMediator> mediator)
			: m_renderer(renderer)
			, m_mediator(mediator)
			, m_session(nullptr)
			, m_textureSet(nullptr)
			, m_mirrorTexture(nullptr)
			, m_fboId(0)
			, m_fboDepthAttachmentId(0)
		{
			m_mediator->registerDevice(this);
		}

		Rift::~Rift()
		{
			finishOculusVR();
		}

		void Rift::initialize()
		{
			startOculusVR();

			ovrHmdDesc hmdDescriptor = ovr_GetHmdDesc(m_session);

			// The width and height are not const, because the renderer may change them during initialization.
			//
			std::uint16_t width = hmdDescriptor.Resolution.w;
			std::uint16_t height = hmdDescriptor.Resolution.h;

			m_renderer->initialize(width, height);

			setupOculusRiftRendering();
		}

		void Rift::render()
		{
			// TODO: update the headset orientation
			// TODO: render
		}

		void Rift::startOculusVR()
		{
			ovrResult result = ovrSuccess;

			result = ovr_Initialize(nullptr);

			if (OVR_FAILURE(result))
			{
				ovrErrorInfo errorInfo;
				ovr_GetLastErrorInfo(&errorInfo);

				// TODO: throw an appropriate exception
			}
			auto ovrInitializationReverse = helpers::guard_scope([] { ovr_Shutdown(); });

			ovrSession session;
			ovrGraphicsLuid luid;

			result = ovr_Create(&session, &luid);

			if (OVR_FAILURE(result))
			{
				ovrErrorInfo errorInfo;
				ovr_GetLastErrorInfo(&errorInfo);

				// TODO: throw an appropriate exception
			}
			auto ovrCreationReverse = helpers::guard_scope([session] { ovr_Destroy(session); });

			m_session = session;

			ovrCreationReverse.dismiss();
			ovrInitializationReverse.dismiss();
		}

		void Rift::finishOculusVR()
		{
			ovr_Destroy(m_session);
			ovr_Shutdown();
		}

		void Rift::setupOculusRiftRendering()
		{
			//
			// Setup the size of a single texture which will be shared by both eyes.
			//

			ovrHmdDesc hmdDescriptor = ovr_GetHmdDesc(m_session);

			ovrSizei leftEyeTextureSize = ovr_GetFovTextureSize(m_session, ovrEye_Left, hmdDescriptor.DefaultEyeFov[ovrEye_Left], 1.0f);
			ovrSizei rightEyeTextureSize = ovr_GetFovTextureSize(m_session, ovrEye_Right, hmdDescriptor.DefaultEyeFov[ovrEye_Right], 1.0f);

			// Calculate the size of the shared texture.
			//
			ovrSizei bufferSize;
			bufferSize.w = leftEyeTextureSize.w + rightEyeTextureSize.w;
			bufferSize.h = std::max(leftEyeTextureSize.h, rightEyeTextureSize.h);


			//
			// Setup Oculus swap texture set.
			//

			ovrResult result = ovrSuccess;

			// Create a texture set which represent buffers for eye rendering.
			//
			ovrSwapTextureSet * textureSet = nullptr;
			result = ovr_CreateSwapTextureSetGL(m_session, GL_SRGB8_ALPHA8, bufferSize.w, bufferSize.h, &textureSet);

			if (OVR_FAILURE(result))
			{
				ovrErrorInfo errorInfo;
				ovr_GetLastErrorInfo(&errorInfo);

				// TODO: throw an appropriate exception
			}
			auto textureSetCreationReverse = helpers::guard_scope([this, textureSet] { ovr_DestroySwapTextureSet(m_session, textureSet); });

			// Initialize the textures in the set.
			//
			for (int i = 0; i < textureSet->TextureCount; ++i)
			{
				ovrGLTexture* tex = (ovrGLTexture*)&textureSet->Textures[i];

				glBindTexture(GL_TEXTURE_2D, tex->OGL.TexId);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			}


			//
			// Setup OpenGL framebuffer object that is used for offscreen rendering to the Rift.
			//

			GLsizei const generatedFBOsCount = 1;
			GLsizei const generatedTexturesCount = 1;

			glGenFramebuffers(generatedFBOsCount, &m_fboId);

			// Configure the depth attachment texture of the framebuffer object.
			//
			glGenTextures(generatedTexturesCount, &m_fboDepthAttachmentId);
			glBindTexture(GL_TEXTURE_2D, m_fboDepthAttachmentId);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			GLenum internalFormat = GL_DEPTH_COMPONENT24;
			GLenum type = GL_UNSIGNED_INT;
			glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, bufferSize.w, bufferSize.h, 0, GL_DEPTH_COMPONENT, type, NULL);


			//
			// Setup a framebuffer object that is used for offscreen rendering to the display.
			//

			// Create a mirror texture to display the render result in the underlying display window.
			//
			ovrGLTexture * mirrorTexture = nullptr;
			result = ovr_CreateMirrorTextureGL(m_session, GL_SRGB8_ALPHA8, m_windowWidth, m_windowHeight, reinterpret_cast<ovrTexture**>(&mirrorTexture));

			if (OVR_FAILURE(result))
			{
				ovrErrorInfo errorInfo;
				ovr_GetLastErrorInfo(&errorInfo);

				// TODO: throw an appropriate exception
			}
			auto mirrorTextureCreationReverse = helpers::guard_scope([this, mirrorTexture] { ovr_DestroyMirrorTexture(m_session, &mirrorTexture->Texture); });

			// Bind the mirror texture to the framebuffer object.
			//
			glGenFramebuffers(1, &m_mirrorFBOId);
			glBindFramebuffer(GL_READ_FRAMEBUFFER, m_mirrorFBOId);
			glFramebufferTexture2D(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mirrorTexture->OGL.TexId, 0);
			glFramebufferRenderbuffer(GL_READ_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, 0);
			glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);

			mirrorTextureCreationReverse.dismiss();
			textureSetCreationReverse.dismiss();

			m_mirrorTexture = mirrorTexture;
			m_textureSet = textureSet;
		}

		void Rift::resize(std::uint16_t width, std::uint16_t height)
		{
			// TODO : implement
		}
	}
}
