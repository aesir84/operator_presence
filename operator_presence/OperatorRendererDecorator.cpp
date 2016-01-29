#include "stdafx.h"

#include "OperatorRendererDecorator.h"

namespace operator_view
{
	OperatorRendererDecorator::OperatorRendererDecorator(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
		: m_decoratedOperatorRenderer(operatorRendererToDecorate)
	{ }
}
