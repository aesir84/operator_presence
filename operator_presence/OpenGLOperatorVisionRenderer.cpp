#include "stdafx.h"

#include "OpenGLOperatorVisionRenderer.h"

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

		OperatorVisionRenderer::OperatorVisionRenderer()
			: m_verticesPositions(QOpenGLBuffer::VertexBuffer)
		{ }

		void OperatorVisionRenderer::initialize()
		{
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

		void OperatorVisionRenderer::render()
		{
		}

		void OperatorVisionRenderer::initShader()
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

		void OperatorVisionRenderer::updateLeftEyeImage(std::shared_ptr<QImage> leftEyeImage)
		{
		}

		void OperatorVisionRenderer::updateRightEyeImage(std::shared_ptr<QImage> rightEyeImage)
		{
		}
	}
}
