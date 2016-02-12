#pragma once

#include "IOperatorVision.h"

namespace operator_model
{
	class OperatorVision : public IOperatorVision
	{
	public:
		OperatorVision();

	public:
		virtual void setLeftEyeImage(std::shared_ptr<QImage> leftEyeImage) override;
		virtual void setRightEyeImage(std::shared_ptr<QImage> rightEyeImage) override;

	private:
		std::shared_ptr<QImage> m_leftEyeImage;
		std::shared_ptr<QImage> m_rightEyeImage;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) override;

	private:
		virtual void notifyLeftEyeImageChanged(std::shared_ptr<QImage> leftEyeImage) override;
		virtual void notifyRightEyeImageChanged(std::shared_ptr<QImage> rightEyeImage) override;

	private:
		std::vector<std::weak_ptr<IOperatorVisionObserver>> m_observers;
	};
}

