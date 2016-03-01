#pragma once

#include "OperatorEyeImageType.h"

namespace operator_model
{
	class IOperatorVisionObserver
	{
	public:
		virtual ~IOperatorVisionObserver() { }

	public:
		virtual void updateLeftEyeImageChanged(EyeImage leftEyeImage) = 0;
		virtual void updateRightEyeImageChanged(EyeImage rightEyeImage) = 0;
	};
}
