#pragma once

namespace operator_model
{
	class IObservableOperatorVision;
}

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
		virtual std::shared_ptr<IRenderer> createOperatorVisionRenderer(operator_model::IObservableOperatorVision & operatorVision) = 0;
	};
}
