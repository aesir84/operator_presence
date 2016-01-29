#pragma once

#include "IRendererFactory.h"

namespace operator_view
{
	namespace opengl
	{
		class RendererFactory : public IRendererFactory
		{
		private:
			virtual std::shared_ptr<IOperatorRenderer> createOperatorRenderer() override;
			virtual std::shared_ptr<IOperatorRenderer> createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> rendererToDecorate) override;
		};
	}
}
