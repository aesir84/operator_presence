#pragma once

#include "IOperatorViewRift.h"

namespace operator_view
{
	class IMediator;
	class IRenderer;
}

namespace operator_view
{
	namespace opengl
	{
		class Rift : public IRift
		{
			friend class Factory;

		private:
			Rift(std::shared_ptr<IRenderer> renderer, std::shared_ptr<IMediator> mediator);

		public:
			~Rift();

		private:
			std::shared_ptr<IRenderer> m_renderer;
			std::shared_ptr<IMediator> m_mediator;

		private:
			virtual void initialize() override;
			virtual void render() override;

		private:
			void startOculusVR();
			void finishOculusVR();

			void setupOculusRiftRendering();

		private:
			ovrSession m_session;
			ovrSwapTextureSet * m_textureSet;
			ovrGLTexture * m_mirrorTexture;

		private:
			GLuint m_fboId;
			GLuint m_fboDepthAttachmentId;

			GLuint m_mirrorFBOId;

		private:
			virtual void resize(std::uint16_t width, std::uint16_t height) override;
		};
	}
}
