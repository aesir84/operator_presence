#pragma once

#include "IRendererFactory.h"

namespace operator_view
{
	namespace opengl
	{
		class RendererFactory : public IRendererFactory
		{
		private:
			virtual std::shared_ptr<IRenderer> createWindowRenderer() override;
			virtual std::shared_ptr<IRenderer> createOperatorVisionRenderer(std::shared_ptr<IRenderer> rendererToDecorate) override;
		};
	}
}
