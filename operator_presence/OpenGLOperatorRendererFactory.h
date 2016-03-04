#pragma once

#include "IOperatorRendererFactory.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorRendererFactory : public IOperatorRendererFactory
		{
		private:
			virtual std::shared_ptr<IOperatorDisplayRenderer> createOperatorDisplayRenderer() override;
			virtual std::shared_ptr<IOperatorVisionRenderer> createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate) override;
		};
	}
}
