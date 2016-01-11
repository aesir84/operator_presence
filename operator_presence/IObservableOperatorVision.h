#pragma once

namespace model
{
	class IOperatorVisionObserver;
}

namespace model
{
	class IObservableOperatorVision
	{
	public:
		virtual ~IObservableOperatorVision() { }

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) = 0;

	private:
		virtual void notifyLeftEyeImageUpdate(std::shared_ptr<QImage> leftEyeImage) = 0;
		virtual void notifyRightEyeImageUpdate(std::shared_ptr<QImage> rightEyeImage) = 0;
	};
}
