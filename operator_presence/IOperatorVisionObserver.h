#pragma once

#include "OperatorEyeImageType.h"

namespace operator_model
{
	class IOperatorVisionObserver
	{
	public:
		virtual ~IOperatorVisionObserver() { }

	public:
		virtual void updateLeftEyeImage(EyeImage leftEyeImage) = 0;
		virtual void updateRightEyeImage(EyeImage rightEyeImage) = 0;
	};
}
