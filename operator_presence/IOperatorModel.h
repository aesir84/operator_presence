#pragma once

namespace operator_model
{
	class IOperatorHeadOrientationObserver;
	class IOperatorVisionObserver;
}

namespace operator_model
{
	class IOperatorModel
	{
	public:
		virtual ~IOperatorModel() { }

	public:
		virtual void turnBody(double yaw) = 0;
		virtual void turnHead(double yaw, double pitch, double roll) = 0;

	public:
		virtual void switchVision(/* to what */) = 0;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorHeadOrientationObserver> observer) = 0;
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) = 0;
	};
}
