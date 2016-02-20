#pragma once

namespace operator_model
{
	namespace utils
	{
		class IImageInputStream;
		class IImageOutputStream;
	}
}

namespace operator_model
{
	class IOperatorVisionReaderObserver;
}

namespace operator_model
{
	class IOperatorVisionReader
	{
	public:
		virtual ~IOperatorVisionReader() { }

	public:
		virtual void setReadStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream) = 0;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionReaderObserver> observer) = 0;

	private:
		virtual void notifyLeftEyeImageRead(EyeImage leftEyeImage) = 0;
		virtual void notifyRightEyeImageRead(EyeImage rightEyeImage) = 0;
	};
}
