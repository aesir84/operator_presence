#pragma once

namespace operator_view
{
	class IRenderer;
}

namespace operator_view
{
	class IRendererFactory
	{
	public:
		virtual ~IRendererFactory() { }

	public:
		virtual std::shared_ptr<IRenderer> createWindowRenderer() = 0;
		virtual std::shared_ptr<IRenderer> createOperatorVisionRenderer(std::shared_ptr<IRenderer> rendererToDecorate) = 0;
	};
}
