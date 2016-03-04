#pragma once

namespace operator_view
{
	class IOperatorRendererObserver
	{
	public:
		virtual ~IOperatorRendererObserver() { }

	public:
		virtual void updateKeyPressed(Qt::Key key) = 0;
		virtual void updateSizeChanged(std::uint16_t newWidth, std::uint16_t newHeight) = 0;
		virtual void updateHeadOrientationChanged(double yaw, double pitch, double roll) = 0;
	};
}
