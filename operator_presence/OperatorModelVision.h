#pragma once

#include "IOperatorVision.h"

namespace operator_model
{
	class OperatorVision : public IOperatorVision
	{
	public:
		OperatorVision();

	public:
		virtual void setUpdateStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream) override;

	private:
		class EyeImageUpdater;

		std::unique_ptr<EyeImageUpdater> m_leftEyeImageUpdater;
		std::unique_ptr<EyeImageUpdater> m_rightEyeImageUpdater;

	private:
		void updateLeftEyeImage(EyeImage leftEyeImage);
		void updateRightEyeImage(EyeImage rightEyeImage);

	private:
		std::atomic<bool> m_leftEyeImageUpdated;
		std::atomic<bool> m_rightEyeImageUpdated;

	private:
		EyeImage m_leftEyeImage;
		EyeImage m_rightEyeImage;

	private:
		virtual bool getUpdate(EyeImage & leftEyeImage, EyeImage & rightEyeImage) override;

	private:
		std::mutex m_eyeImagesGuard;
	};
}

