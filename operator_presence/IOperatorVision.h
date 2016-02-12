#pragma once

namespace operator_model
{
	class IOperatorVisionObserver;
}

namespace operator_model
{
	class IOperatorVision
	{
	public:
		virtual ~IOperatorVision() { }

	public:
		virtual void setLeftEyeImage(std::shared_ptr<QImage> leftEyeImage) = 0;
		virtual void setRightEyeImage(std::shared_ptr<QImage> rightEyeImage) = 0;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) = 0;

	private:
		virtual void notifyLeftEyeImageChanged(std::shared_ptr<QImage> leftEyeImage) = 0;
		virtual void notifyRightEyeImageChanged(std::shared_ptr<QImage> rightEyeImage) = 0;
	};
}
