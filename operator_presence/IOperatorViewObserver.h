#pragma once

namespace operator_view
{
	class IOperatorViewObserver
	{
	public:
		virtual ~IOperatorViewObserver() { }

	public:
		virtual void updateHeadsetOrientationChanged(double yaw, double pitch, double roll) = 0;
		virtual void updateVisionSelected(std::uint32_t visionId) = 0;
	};
}
