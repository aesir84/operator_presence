#include "stdafx.h"

#include "OperatorVision.h"

#include "IOperatorVisionObserver.h"

#include "IImageInputStream.h"

namespace operator_model
{
	OperatorVision::OperatorVision()
		: m_leftEyeInputStreamingStopped(true)
		, m_rightEyeInputStreamingStopped(true)
	{ }

	void OperatorVision::setLeftEyeInputStream(std::shared_ptr<utils::IImageInputStream> stream)
	{
		if (!m_leftEyeInputStreamingStopped)
		{
			assert(false);
			return;
		}

		m_leftEyeInputStream = stream;
	}

	void OperatorVision::setRightEyeInputStream(std::shared_ptr<utils::IImageInputStream> stream)
	{
		if (!m_rightEyeInputStreamingStopped)
		{
			assert(false);
			return;
		}

		m_rightEyeInputStream = stream;
	}

	void OperatorVision::startLeftEyeStreaming()
	{
		assert(m_leftEyeInputStreamingStopped);
		assert(m_leftEyeInputStream != nullptr);

		m_leftEyeInputStreamingStopped = false;

		while (!m_leftEyeInputStreamingStopped)
		{
			m_leftEyeImage = m_leftEyeInputStream->read();

			notifyLeftEyeImageChanged(m_leftEyeImage);
		}
	}

	void OperatorVision::stopLeftEyeStreaming()
	{
		assert(!m_leftEyeInputStreamingStopped);

		m_leftEyeInputStreamingStopped = true;
	}

	void OperatorVision::startRightEyeStreaming()
	{
		assert(m_rightEyeInputStreamingStopped);
		assert(m_rightEyeInputStream != nullptr);

		m_rightEyeInputStreamingStopped = false;

		while (!m_rightEyeInputStreamingStopped)
		{
			m_rightEyeImage = m_rightEyeInputStream->read();

			notifyRightEyeImageChanged(m_rightEyeImage);
		}
	}

	void OperatorVision::stopRightEyeStreaming()
	{
		m_rightEyeInputStreamingStopped = true;
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
