#pragma once

namespace operator_model
{
	class IOperatorVisionObserver;
}

namespace operator_model
{
	class IObservableOperatorVision
	{
	public:
		virtual ~IObservableOperatorVision() { }

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) = 0;

	private:
		virtual void notifyLeftEyeImageChanged(EyeImage leftEyeImage) = 0;
		virtual void notifyRightEyeImageChanged(EyeImage rightEyeImage) = 0;
	};
}
