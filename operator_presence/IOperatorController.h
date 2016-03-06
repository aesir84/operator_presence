#pragma once

namespace operator_controller
{
	class IOperatorDisplay;
	class IOperatorHeadset;
}

namespace operator_controller
{
	class IOperatorController
	{
	public:
		virtual ~IOperatorController() { }

	public:
		virtual void registerOperatorDisplay(IOperatorDisplay * operatorDisplay) = 0;
		virtual void registerOperatorHeadset(IOperatorHeadset * operatorHeadset) = 0;

	public:
		virtual void updateHeadsetOrientationChanged(double yaw, double pitch, double roll) = 0;
		virtual void updateKeyPressed(Qt::Key key) = 0;
		virtual void updateWindowExposed(WId windowId) = 0;
		virtual void updateWindowSizeChanged(std::uint16_t width, std::uint16_t height) = 0;
	};
}
