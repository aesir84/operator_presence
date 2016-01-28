#pragma once

#include "IObservableOperatorVision.h"

namespace operator_model
{
	class OperatorVision : public IObservableOperatorVision
	{
	public:
		OperatorVision();

	public:
		void updateLeftEyeImage(std::shared_ptr<QImage> leftEyeImage);
		void updateRightEyeImage(std::shared_ptr<QImage> rightEyeImage);

	private:
		std::shared_ptr<QImage> m_leftEyeImage;
		std::shared_ptr<QImage> m_rightEyeImage;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) override;

	private:
		virtual void notifyLeftEyeImageUpdate(std::shared_ptr<QImage> leftEyeImage) override;
		virtual void notifyRightEyeImageUpdate(std::shared_ptr<QImage> rightEyeImage) override;

	private:
		std::vector<std::weak_ptr<IOperatorVisionObserver>> m_observers;
	};
}

