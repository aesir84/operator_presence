#pragma once

namespace operator_view
{
	class IOperatorRenderer;
}

namespace operator_view
{
	class IRendererFactory
	{
	public:
		virtual ~IRendererFactory() { }

	public:
		virtual std::shared_ptr<IOperatorRenderer> createOperatorRenderer() = 0;
		virtual std::shared_ptr<IOperatorRenderer> createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> rendererToDecorate) = 0;
	};
}
