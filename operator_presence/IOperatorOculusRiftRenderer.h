#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	class IOperatorOculusRiftRenderer : public IOperatorRenderer
	{
	public:
		IOperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate);

	public:
		virtual void exec() = 0;
		virtual void shutdown() = 0;

	protected:
		std::shared_ptr<IOperatorRenderer> m_decoratedOperatorRenderer;
	};
}
