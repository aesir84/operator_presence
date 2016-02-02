#pragma once

namespace operator_view
{
	class IOperatorViewObserver
	{
	public:
		virtual ~IOperatorViewObserver() { }

	public:
		virtual void updateKeyPressed(Qt::Key key) = 0;
		virtual void updateSizeChanged(std::uint16_t newWidth, std::uint16_t newHeight) = 0;
		virtual void updateOrientationChanged(double yaw, double pitch, double roll) = 0;
		virtual void updateErrorOccured(std::string const & errorDescription) = 0;
	};
}
