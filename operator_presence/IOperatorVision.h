#pragma once

#include "OperatorEyeImageType.h"

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
	class IOperatorVisionObserver;
}

namespace operator_model
{
	class IOperatorVision
	{
	public:
		virtual ~IOperatorVision() { }

	public:
		virtual void setInputStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream) = 0;
		virtual void setOutputStrategy(std::shared_ptr<utils::IImageOutputStream> leftEyeStream, std::shared_ptr<utils::IImageOutputStream> rightEyeStream) = 0;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) = 0;

	private:
		virtual void notifyLeftEyeImageChanged(EyeImage leftEyeImage) = 0;
		virtual void notifyRightEyeImageChanged(EyeImage rightEyeImage) = 0;
	};
}
