#pragma once

namespace operator_model
{
	class IOperatorVisionObserver
	{
	public:
		virtual ~IOperatorVisionObserver() { }

	public:
		virtual void updateLeftEyeImage(std::shared_ptr<QImage> leftEyeImage) = 0;
		virtual void updateRightEyeImage(std::shared_ptr<QImage> rightEyeImage) = 0;
	};
}
