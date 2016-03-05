#pragma once

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
		virtual std::shared_ptr<IOperatorDisplayRenderer> createOperatorDisplayRenderer() = 0;
		virtual std::shared_ptr<IOperatorOculusRiftStrategy> createOperatorOculusRiftStrategy(std::shared_ptr<IOperatorViewRenderer> renderer) = 0;
		virtual std::shared_ptr<IOperatorVisionDecorator> createOperatorVisionDecorator(std::shared_ptr<IOperatorViewRenderer> decoratedRenderer) = 0;
	};
}
