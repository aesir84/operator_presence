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
			virtual void updateLeftEyeImage(std::shared_ptr<QImage> leftEyeImage) override;
			virtual void updateRightEyeImage(std::shared_ptr<QImage> rightEyeImage) override;

		private:
			std::unique_ptr<QOpenGLTexture> m_leftEyeTexture;
			std::unique_ptr<QOpenGLTexture> m_rightEyeTexture;
		};
	}
}
