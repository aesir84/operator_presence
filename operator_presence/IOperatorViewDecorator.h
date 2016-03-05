#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	/// \brief A decorator interface for the operator view renderers
	///
	/// This is a base class for concrete decorators of IOperatorViewRenderer interfaces.
	/// The decorators must not depend on a concrete windowing subsystem,
	/// all they have to care about is drawing their 3-D scenes using one low level 3-D API or another.
	///
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
