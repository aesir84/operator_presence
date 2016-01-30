#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	class IOperatorOculusRiftRenderer : public IOperatorRenderer
	{
	public:
		IOperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate);

	protected:
		std::shared_ptr<IOperatorRenderer> m_decoratedOperatorRenderer;
	};
}
