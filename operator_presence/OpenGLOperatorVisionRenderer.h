#pragma once

#include "IOperatorVisionRenderer.h"
#include "OperatorEyeImageRenderType.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorVisionRenderer : public IOperatorVisionRenderer
		{
			friend class OperatorRendererFactory;

		private:
			OperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> rendererToDecorate);

		private:
			virtual void initialize(std::uint16_t eyeResolutionWidth, std::uint16_t eyeResolutionHeight) override;

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
			std::array<std::mutex, helpers::as_integer(Eye::Count)> m_eyeTextureMutexes;

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
			virtual void updateLeftEyeImageChanged(EyeImage leftEyeImage) override;
			virtual void updateRightEyeImageChanged(EyeImage rightEyeImage) override;

		private:
			void updateEyeImage(Eye eye, EyeImage image);
		};
	}
}
