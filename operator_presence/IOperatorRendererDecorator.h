#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	class IOperatorRendererDecorator : public IOperatorRenderer
	{
	public:
		IOperatorRendererDecorator(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
			: m_decoratedOperatorRenderer(operatorRendererToDecorate)
		{ }

	protected:
		std::shared_ptr<IOperatorRenderer> m_decoratedOperatorRenderer;
	};
}
