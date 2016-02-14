#pragma once

namespace operator_model
{
	class IOperatorVisionObserver;
}

namespace operator_model
{
	namespace utils
	{
		class IImageInputStream;
	}
}

namespace operator_model
{
	class IOperatorVision
	{
	public:
		virtual ~IOperatorVision() { }

	public:
		virtual void setLeftEyeInputStream(std::shared_ptr<utils::IImageInputStream> stream) = 0;
		virtual void setRightEyeInputStream(std::shared_ptr<utils::IImageInputStream> stream) = 0;

	public:
		virtual void startLeftEyeStreaming() = 0;
		virtual void stopLeftEyeStreaming() = 0;

		virtual void startRightEyeStreaming() = 0;
		virtual void stopRightEyeStreaming() = 0;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) = 0;

	private:
		virtual void notifyLeftEyeImageChanged(std::shared_ptr<QImage> leftEyeImage) = 0;
		virtual void notifyRightEyeImageChanged(std::shared_ptr<QImage> rightEyeImage) = 0;
	};
}
