#pragma once

namespace operator_model
{
	class IOperatorHeadOrientationObserver;
}

namespace operator_model
{
	class IOperatorHeadOrientation
	{
	public:
		virtual ~IOperatorHeadOrientation() { }

	public:
		virtual void setHeadOrientation(double yaw, double pitch, double roll) = 0;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorHeadOrientationObserver> observer) = 0;

	private:
		virtual void notifyHeadOrientationChanged(double yaw, double pitch, double roll) = 0;
	};
}
