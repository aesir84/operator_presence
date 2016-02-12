#include "stdafx.h"

#include "OperatorVision.h"

#include "IOperatorVisionObserver.h"

namespace operator_model
{
	OperatorVision::OperatorVision()
	{ }

	void OperatorVision::setLeftEyeImage(std::shared_ptr<QImage> leftEyeImage)
	{
		m_leftEyeImage = leftEyeImage;

		notifyLeftEyeImageChanged(m_leftEyeImage);
	}

	void OperatorVision::setRightEyeImage(std::shared_ptr<QImage> rightEyeImage)
	{
		m_rightEyeImage = rightEyeImage;

		notifyRightEyeImageChanged(m_rightEyeImage);
	}

	void OperatorVision::registerObserver(std::shared_ptr<IOperatorVisionObserver> observer)
	{
		m_observers.push_back(observer);
	}

	void OperatorVision::notifyLeftEyeImageChanged(std::shared_ptr<QImage> leftEyeImage)
	{
		for (auto & observer : m_observers)
		{
			auto existingObserver = observer.lock();

			if (existingObserver)
			{
				existingObserver->updateLeftEyeImage(leftEyeImage);
			}
		}
	}

	void OperatorVision::notifyRightEyeImageChanged(std::shared_ptr<QImage> rightEyeImage)
	{
		for (auto & observer : m_observers)
		{
			auto existingObserver = observer.lock();

			if (existingObserver)
			{
				existingObserver->updateRightEyeImage(rightEyeImage);
			}
		}
	}
}
