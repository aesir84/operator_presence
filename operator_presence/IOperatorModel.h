#pragma once

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
		virtual void switchVision(std::uint32_t visionId) = 0;

	public:
		virtual bool getEyeImages(EyeImage & leftEyeImage, EyeImage & rightEyeImage) = 0;
	};
}
