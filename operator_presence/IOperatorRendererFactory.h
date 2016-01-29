#pragma once

namespace operator_view
{
	class IOperatorDisplayRenderer;
}

namespace operator_view
{
	class IOperatorRendererFactory
	{
	public:
		virtual ~IOperatorRendererFactory() { }

	public:
		virtual std::shared_ptr<IOperatorDisplayRenderer> createOperatorDisplayRenderer() = 0;
		virtual std::shared_ptr<IOperatorRenderer> createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate) = 0;
	};
}
