#include "stdafx.h"

#include "OpenGLOperatorViewVision.h"

#include "IOperatorViewMediator.h"

namespace operator_view
{
	namespace opengl
	{
		namespace
		{
			// A simple square where to draw the eye textures.
			// The square consists of two triangles.
			//
			QVector<QVector3D> const verticesPositionData = {
				{ -1.0f, -1.0f, 0.0f },
				{ 1.0f, -1.0f, 0.0f },
				{ -1.0f,  1.0f, 0.0f },
				{ -1.0f,  1.0f, 0.0f },
				{ 1.0f, -1.0f, 0.0f },
				{ 1.0f,  1.0f, 0.0f },
			};
		}

		Vision::Vision(std::shared_ptr<IRenderer> decoratedRenderer, std::shared_ptr<IMediator> mediator)
			: IVision(decoratedRenderer)
			, m_mediator(mediator)
			, m_verticesPositions(QOpenGLBuffer::VertexBuffer)
		{
			m_mediator->registerVision(this);
		}

		void Vision::initialize(std::uint16_t & width, std::uint16_t & height)
		{
			// Firstly, let the decorated renderer (most likely the window) perform its initialization.
			//
			m_decoratedRenderer->initialize(width, height);

			m_vao.create();
			m_vao.bind();

			m_verticesPositions.create();
			m_verticesPositions.setUsagePattern(QOpenGLBuffer::StaticDraw);
			m_verticesPositions.bind();
			m_verticesPositions.allocate(verticesPositionData.constData(), verticesPositionData.size() * sizeof(QVector3D));
			m_verticesPositions.release();

			initShader();

			m_shader.bind();

			m_verticesPositions.bind();
			m_shader.enableAttributeArray(m_vertexPositionAttribute);
			m_shader.setAttributeBuffer(m_vertexPositionAttribute, GL_FLOAT, 0, 3);
			m_verticesPositions.release();

			m_shader.release();
			m_vao.release();
		}

		void Vision::renderLeftEye()
		{
			m_decoratedRenderer->renderLeftEye();
			render(Eye::Left);
		}

		void Vision::renderRightEye()
		{
			m_decoratedRenderer->renderRightEye();
			render(Eye::Right);
		}

		void Vision::render(Eye eye)
		{
			std::lock_guard<std::mutex> textureAccess(m_eyeTextureMutexes[helpers::as_integer(eye)]);

			m_shader.bind();
			m_eyeTextures[helpers::as_integer(eye)]->bind();
			m_vao.bind();

			QOpenGLContext::currentContext()->functions()->glDrawArrays(GL_TRIANGLES, 0, 6);

			m_vao.release();
			m_eyeTextures[helpers::as_integer(eye)]->release();
			m_shader.release();
		}

		void Vision::initShader()
		{
			QString const vertexShaderSource("#version 330 core\n"
				"layout(location = 0) in vec3 vertexPosition;\n"
				"out vec2 UV;\n"
				"void main()\n"
				"{\n"
				"    gl_Position = vec4(vertexPosition, 1);\n"
				"    UV = (vertexPosition.xy + vec2(1, 1)) / 2.0;\n"
				"}\n");

			QString const fragmentShaderSource("#version 330 core\n"
				"in vec2 UV;\n"
				"out vec3 color;\n"
				"uniform sampler2D textureSampler;\n"
				"void main()\n"
				"{\n"
				"    color = texture2D(textureSampler, UV).rgb;\n"
				"}\n");

			m_shader.addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
			m_shader.addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
			m_shader.link();
		}

		void Vision::updateLeftEyeImage(Image leftEyeImage)
		{
			updateEyeImage(Eye::Left, leftEyeImage);
		}

		void Vision::updateRightEyeImage(Image rightEyeImage)
		{
			updateEyeImage(Eye::Right, rightEyeImage);
		}

		void Vision::updateEyeImage(Eye eye, Image image)
		{
			// Convert the image to a format which is used by OpenGL textures in Qt.
			// RGBA8888 is a 32-bit byte-ordered RGBA format (8-8-8-8).
			// This byte-by-byte interpretation suits OpenGL textures.
			//
			auto const textureImage = image.convertToFormat(QImage::Format_RGBA8888);


			//
			// Either create a new texture or refill the already existing one.
			//

			if (m_eyeTextures[helpers::as_integer(eye)] == nullptr)
			{
				// Create a texture from the supplied image.
				//
				std::lock_guard<std::mutex> textureAccess(m_eyeTextureMutexes[helpers::as_integer(eye)]);
				m_eyeTextures[helpers::as_integer(eye)] = std::make_unique<QOpenGLTexture>(textureImage);
			}
			else
			{
				// Update the pixels of the existing texture.
				//
				std::lock_guard<std::mutex> textureAccess(m_eyeTextureMutexes[helpers::as_integer(eye)]);
				m_eyeTextures[helpers::as_integer(eye)]->setData(QOpenGLTexture::RGBA, QOpenGLTexture::UInt8, textureImage.bits());
			}
		}
	}
}
