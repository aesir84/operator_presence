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
		void updateLeftEyeImage(EyeImage eyeImage);
		void updateRightEyeImage(EyeImage eyeImage);

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) override;

	private:
		virtual void notifyLeftEyeImageChanged(EyeImage leftEyeImage) override;
		virtual void notifyRightEyeImageChanged(EyeImage rightEyeImage) override;

	private:
		std::vector<std::weak_ptr<IOperatorVisionObserver>> m_observers;
	};
}

