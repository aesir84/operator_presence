#pragma once

#include "IOperatorVisionObserver.h"
#include "IRenderer.h"

namespace view
{
	namespace opengl
	{
		class OperatorVisionRenderer : public IRenderer, public model::IOperatorVisionObserver
		{
			friend class RendererFactory;

		private:
			OperatorVisionRenderer();

		private:
			virtual void initialize() override;
			virtual void render() override;

		private:
			QOpenGLVertexArrayObject m_vao;
			QOpenGLBuffer m_verticesPositions;
			GLuint m_vertexPositionAttribute;

		private:
			void initShader();

		private:
			QOpenGLShaderProgram m_shader;

		private:
			virtual void updateLeftEyeImage(std::shared_ptr<QImage> leftEyeImage) override;
			virtual void updateRightEyeImage(std::shared_ptr<QImage> rightEyeImage) override;

		private:
			std::unique_ptr<QOpenGLTexture> m_leftEyeTexture;
			std::unique_ptr<QOpenGLTexture> m_rightEyeTexture;
		};
	}
}
