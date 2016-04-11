#pragma once

namespace operator_view
{
	class IDevice;
	class IWindow;
	class IVision;
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
		virtual void registerVision(IVision * vision) = 0;

	public:
		virtual void notifyDeviceOrientationChanged(double yaw, double pitch, double roll) = 0;
		virtual void notifyEscapeKeyPressed() = 0;
		virtual void notifyWindowSizeChanged(std::uint16_t width, std::uint16_t height) = 0;
	};
}
