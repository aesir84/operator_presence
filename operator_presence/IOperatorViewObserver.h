#pragma once

namespace operator_view
{
	class IOperatorViewObserver
	{
	public:
		virtual ~IOperatorViewObserver() { }

	public:
		virtual void updateHeadsetOrientationChanged(double yaw, double pitch, double roll) = 0;
		virtual void updateKeyPressed(Qt::Key key) = 0;
		virtual void updateVisionSelected(std::uint32_t visionId) = 0;
		virtual void updateWindowExposed(WId windowId) = 0;
		virtual void updateWindowSizeChanged(std::uint16_t width, std::uint16_t height) = 0;
	};
}
