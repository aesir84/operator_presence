#pragma once

namespace operator_view
{
	class IMediator;
	class IRenderer;
	class IRift;
	class IVision;
	class IWindow;
}

namespace operator_view
{
	class IFactory
	{
	public:
		virtual ~IFactory() { }

	public:
		virtual std::shared_ptr<IRift> createRift(std::shared_ptr<IRenderer> renderer, std::shared_ptr<IMediator> mediator) = 0;
		virtual std::shared_ptr<IVision> createVision(std::shared_ptr<IRenderer> decoratedRenderer) = 0;
		virtual std::shared_ptr<IWindow> createWindow(std::shared_ptr<IMediator> mediator) = 0;
	};
}
