#pragma once

namespace operator_model
{
	class IOperatorHeadOrientationObserver
	{
	public:
		virtual ~IOperatorHeadOrientationObserver() { }

	public:
		virtual void updateHeadOrientationChanged(double yaw, double pitch, double roll) = 0;
	};
}
