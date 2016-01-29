#pragma once

#include "IOperatorRendererFactory.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorRendererFactory : public IOperatorRendererFactory
		{
		private:
			virtual std::shared_ptr<IOperatorRenderer> createOperatorRenderer() override;
			virtual std::shared_ptr<IOperatorRenderer> createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> rendererToDecorate) override;
		};
	}
}
