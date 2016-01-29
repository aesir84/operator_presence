#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	class IOperatorVisionRenderer : public IOperatorRenderer
	{
	public:
		IOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate);

	protected:
		std::shared_ptr<IOperatorRenderer> m_decoratedOperatorRenderer;
	};
}
