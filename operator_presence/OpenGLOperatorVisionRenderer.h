#pragma once

#include "IOperatorVisionObserver.h"
#include "OperatorRendererDecorator.h"
#include "scoped_enum_as_integer.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorVisionRenderer : public OperatorRendererDecorator, public operator_model::IOperatorVisionObserver
		{
			friend class OperatorRendererFactory;

		private:
			OperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> rendererToDecorate);

		private:
			virtual void initialize() override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			enum class Eye : std::uint8_t
			{
				Left, Right,
				Count
			};

		private:
			std::array<std::unique_ptr<QOpenGLTexture>, helpers::as_integer(Eye::Count)> m_eyeTextures;

		private:
			void render(Eye eye);

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
			void updateEyeImage(Eye eye, std::shared_ptr<QImage> image);
		};
	}
}
