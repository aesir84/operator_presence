#pragma once

namespace operator_controller
{
	class IOperatorController;
}

namespace operator_view
{
	class IOperatorDisplayRenderer;
	class IOperatorOculusRiftStrategy;
	class IOperatorViewRenderer;
	class IOperatorVisionDecorator;
}

namespace operator_view
{
	class IOperatorViewFactory
	{
	public:
		virtual ~IOperatorViewFactory() { }

	public:
		virtual std::shared_ptr<IOperatorDisplayRenderer> createOperatorDisplayRenderer(std::shared_ptr<operator_controller::IOperatorController> controller) = 0;
		virtual std::shared_ptr<IOperatorOculusRiftStrategy> createOperatorOculusRiftStrategy(std::shared_ptr<IOperatorViewRenderer> renderer, std::shared_ptr<operator_controller::IOperatorController> controller) = 0;
		virtual std::shared_ptr<IOperatorVisionDecorator> createOperatorVisionDecorator(std::shared_ptr<IOperatorViewRenderer> decoratedRenderer) = 0;
	};
}
