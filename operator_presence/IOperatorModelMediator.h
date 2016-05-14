#pragma once

namespace operator_model
{
	class IVision;
}

namespace operator_model
{
	class IMediator
	{
	public:
		virtual ~IMediator() { }

	public:
		virtual void registerVision(IVision * vision) = 0;

	public:
		virtual void notifyLeftEyeImageUpdated(EyeImage leftEyeImage) = 0;
		virtual void notifyRightEyeImageUpdated(EyeImage rightEyeImage) = 0;
	};
}
