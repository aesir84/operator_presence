#pragma once

namespace operator_model
{
	class IOperatorHeadOrientationObserver
	{
	public:
		virtual ~IOperatorHeadOrientationObserver() { }

	public:
		virtual void updateHeadOrientation(double yaw, double pitch, double roll) = 0;
	};
}
