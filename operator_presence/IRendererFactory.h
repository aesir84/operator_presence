#pragma once

namespace model
{
	class IObservableOperatorVision;
	class IObservableWindow;
}

namespace view
{
	class IRenderer;
}

namespace view
{
	class IRendererFactory
	{
	public:
		virtual ~IRendererFactory() { }

	public:
		virtual std::shared_ptr<IRenderer> createWindowRenderer(model::IObservableWindow & window) = 0;
		virtual std::shared_ptr<IRenderer> createOperatorVisionRenderer(model::IObservableOperatorVision & operatorVision) = 0;
	};
}
