#include "stdafx.h"

#include "OperatorVision.h"

#include "IOperatorVisionObserver.h"

namespace model
{
	OperatorVision::OperatorVision()
	{ }

	void OperatorVision::updateLeftEyeImage(std::shared_ptr<QImage> leftEyeImage)
	{
		m_leftEyeImage = leftEyeImage;
	}

	void OperatorVision::updateRightEyeImage(std::shared_ptr<QImage> rightEyeImage)
	{
		m_rightEyeImage = rightEyeImage;
	}

	void OperatorVision::registerObserver(std::shared_ptr<IOperatorVisionObserver> observer)
	{
		m_observers.push_back(observer);
	}

	void OperatorVision::notifyLeftEyeImageUpdate(std::shared_ptr<QImage> leftEyeImage)
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

	void OperatorVision::notifyRightEyeImageUpdate(std::shared_ptr<QImage> rightEyeImage)
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
