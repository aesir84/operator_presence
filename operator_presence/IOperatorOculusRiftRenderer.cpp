#include "stdafx.h"

#include "IOperatorOculusRiftRenderer.h"

namespace operator_view
{
	IOperatorOculusRiftRenderer::IOperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
		: m_decoratedOperatorRenderer(operatorRendererToDecorate)
	{ }
}
