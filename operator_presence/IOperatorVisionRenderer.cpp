#include "stdafx.h"

#include "IOperatorVisionRenderer.h"

namespace operator_view
{
	IOperatorVisionRenderer::IOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
		: m_decoratedOperatorRenderer(operatorRendererToDecorate)
	{ }
}
