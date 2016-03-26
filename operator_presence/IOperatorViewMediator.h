#pragma once

namespace operator_view
{
	class IDevice;
	class IWindow;
}

namespace operator_view
{
	class IMediator
	{
	public:
		virtual ~IMediator() { }

	public:
		virtual void registerDevice(IDevice * device) = 0;
		virtual void registerWindow(IWindow * window) = 0;

	public:
		virtual void notifyEscapeKeyPressed() = 0;
		virtual void notifyWindowCreated(std::uint32_t windowId) = 0;
	};
}
