#pragma once

#include "OperatorEyeImageType.h"

namespace operator_model
{
	namespace utils
	{
		class IImageInputStream;
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
		virtual void setUpdateStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream) = 0;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) = 0;

	private:
		virtual void notifyLeftEyeImageChanged(EyeImage leftEyeImage) = 0;
		virtual void notifyRightEyeImageChanged(EyeImage rightEyeImage) = 0;
	};
}
