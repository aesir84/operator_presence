#pragma once

namespace operator_model
{
	class IObservableOperatorVision;
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
		virtual std::shared_ptr<IRenderer> createOperatorVisionRenderer(operator_model::IObservableOperatorVision & operatorVision) = 0;
	};
}
