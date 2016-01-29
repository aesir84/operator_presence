#pragma once

namespace operator_model
{
	class IObservableOperatorVision;
}

namespace operator_view
{
	class IOperatorDisplayRenderer;
	class IOperatorRenderer;
	class IOperatorVisionRenderer;
}

namespace operator_view
{
	class IOperatorRendererFactory
	{
	public:
		virtual ~IOperatorRendererFactory() { }

	public:
		virtual std::shared_ptr<IOperatorDisplayRenderer> createOperatorDisplayRenderer() = 0;
		virtual std::shared_ptr<IOperatorVisionRenderer> createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate) = 0;
	};
}
