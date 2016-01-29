#pragma once

#include "IOperatorRenderer.h"
#include "IOperatorVisionObserver.h"

namespace operator_view
{
	class IOperatorVisionRenderer : public IOperatorRenderer, public operator_model::IOperatorVisionObserver
	{
	public:
		IOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate);

	protected:
		std::shared_ptr<IOperatorRenderer> m_decoratedOperatorRenderer;
	};
}
