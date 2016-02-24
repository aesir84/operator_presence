#include "stdafx.h"

#include "OperatorVision.h"

#include "IImageInputStream.h"
#include "IOperatorVisionObserver.h"
#include "OperatorEyeImageReader.h"
#include "threadsafe_queue.h"

namespace operator_model
{
	OperatorVision::OperatorVision()
		: m_leftEyeImageReader(std::unique_ptr<detail::OperatorEyeImageReader>(new detail::OperatorEyeImageReader(*this, &OperatorVision::updateLeftEyeImage)))
		, m_rightEyeImageReader(std::unique_ptr<detail::OperatorEyeImageReader>(new detail::OperatorEyeImageReader(*this, &OperatorVision::updateRightEyeImage)))
	{ }

	void OperatorVision::setInputStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream)
	{
		m_leftEyeImageReader->resetReadingStrategy(leftEyeStream);
		m_rightEyeImageReader->resetReadingStrategy(rightEyeStream);
	}

	void OperatorVision::updateLeftEyeImage(EyeImage eyeImage)
	{
		notifyLeftEyeImageChanged(eyeImage);
	}

	void OperatorVision::updateRightEyeImage(EyeImage eyeImage)
	{
		notifyRightEyeImageChanged(eyeImage);
	}

	void OperatorVision::registerObserver(std::shared_ptr<IOperatorVisionObserver> observer)
	{
		m_observers.push_back(observer);
	}

	void OperatorVision::notifyLeftEyeImageChanged(EyeImage leftEyeImage)
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

	void OperatorVision::notifyRightEyeImageChanged(EyeImage rightEyeImage)
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
