#pragma once

namespace operator_model
{
	class IOperatorModel
	{
	public:
		virtual ~IOperatorModel() { }

	public:
		virtual void turnHead(double yaw, double pitch, double roll) = 0;

	public:
		virtual void switchVision(std::uint32_t visionId) = 0;
	};
}
