#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	class OperatorRendererDecorator : public IOperatorRenderer
	{
	public:
		explicit OperatorRendererDecorator(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate);
	protected:
		std::shared_ptr<IOperatorRenderer> m_decoratedOperatorRenderer;
	};
}
