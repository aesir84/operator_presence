#pragma once

namespace operator_view
{
	class IOperatorOculusRiftRenderer;
	class IOperatorRenderer;
}

namespace operator_view
{
	/// \brief A factory to produce renderers of the entire operator's view
	///
	/// The family of the products produced by this abstract factory is defined
	/// by the fact that they all are intended to render the whole operator's view.
	/// Thus, the products of this factory are somewhat mutually exclusive.
	/// On the other hand, as IOperatorViewRenderer interface may be defined as a
	/// strategy to provide the entire rendering mechanism, then it might be
	/// the case when the client wants to create multiple such renderers.
	///
	class IOperatorViewRendererFactory
	{
	public:
		virtual ~IOperatorViewRendererFactory() { }

	public:
		virtual std::shared_ptr<IOperatorOculusRiftRenderer> createOperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRenderer) = 0;
	};
}
