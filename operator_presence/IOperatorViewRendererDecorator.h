#pragma once

#include "IOperatorEyeRenderer.h"

namespace operator_view
{
	/// \brief A decorater interface for the operator renderers
	///
	/// This is a base class for concrete decorators of IOperatorRenderer interfaces.
	/// The decorators must not depend on a concrete windowing subsystem - all they
	/// have to care about is drawing their 3-D scenes using one low level 3-D API or another.
	///
	class IOperatorEyeRendererDecorator : public IOperatorEyeRenderer
	{
	public:
		IOperatorEyeRendererDecorator(std::shared_ptr<IOperatorEyeRenderer> operatorEyeRendererToDecorate)
			: m_decoratedOperatorEyeRenderer(operatorEyeRendererToDecorate)
		{ }

	protected:
		std::shared_ptr<IOperatorEyeRenderer> m_decoratedOperatorEyeRenderer;
	};
}
