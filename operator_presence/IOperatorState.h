#pragma once

namespace operator_model
{
	class IOperatorState
	{
	public:
		virtual ~IOperatorState() { }

	public:
		virtual void turnBody(double yaw) = 0;
		virtual void turnHead(double yaw, double pitch, double roll) = 0;

	public:
		virtual void switchVision(/* to what */) = 0;
	};
}
