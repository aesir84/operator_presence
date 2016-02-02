#pragma once

#include "IOperatorRendererDecorator.h"
#include "IOperatorVisionObserver.h"

namespace operator_view
{
	class IOperatorVisionRenderer : public IOperatorRendererDecorator, public operator_model::IOperatorVisionObserver
	{
	public:
		IOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
			: IOperatorRendererDecorator(operatorRendererToDecorate)
		{ }
	};
}
