#pragma once

#include "IOperatorViewVision.h"

#include "OperatorViewImageType.h"

namespace operator_view
{
	class IMediator;
}

namespace operator_view
{
	namespace opengl
	{
		class Vision : public IVision
		{
			friend class Factory;

		private:
			Vision(std::shared_ptr<IRenderer> decoratedRenderer, std::shared_ptr<IMediator> mediator);

		private:
			std::shared_ptr<IMediator> m_mediator;

		private:
			virtual void initialize(std::uint16_t & width, std::uint16_t & height) override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			enum class Eye : std::uint8_t
			{
				Left, Right,
				Count
			};

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
			virtual void updateLeftEyeImage(Image leftEyeImage) override;
			virtual void updateRightEyeImage(Image rightEyeImage) override;

		private:
			void updateEyeImage(Eye eye, Image image);

		private:
			std::array<std::unique_ptr<QOpenGLTexture>, helpers::as_integer(Eye::Count)> m_eyeTextures;
			std::array<std::mutex, helpers::as_integer(Eye::Count)> m_eyeTextureMutexes;
		};
	}
}
