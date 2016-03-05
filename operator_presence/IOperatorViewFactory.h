#pragma once

namespace operator_view
{
	class IOperatorDisplayRenderer;
	class IOperatorRenderer;
	class IOperatorViewMediator;
	class IOperatorVisionRenderer;
}

namespace operator_view
{
	/// \brief A factory to produce renderers for concrete parts of the operator's view
	///
	/// The produced family of renderers is defined by the fact that they all render their concrete parts of the operator's view.
	/// Variations of this family can be defined by the use of one of the 3-D API, e.g. OpenGL or Direct3D.
	///
	class IOperatorRendererFactory
	{
	public:
		virtual ~IOperatorRendererFactory() { }

	public:
		virtual std::shared_ptr<IOperatorDisplayRenderer> createOperatorDisplayRenderer(std::shared_ptr<IOperatorViewMediator> operatorViewMediator) = 0;
		virtual std::shared_ptr<IOperatorVisionRenderer> createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate, std::shared_ptr<IOperatorViewMediator> operatorViewMediator) = 0;
	};
}
