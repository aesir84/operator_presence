#include "stdafx.h"

#include "OperatorVision.h"

#include "IOperatorVisionObserver.h"
#include "IImageInputStream.h"

namespace operator_model
{
	OperatorVision::OperatorVision()
	{ }

	void OperatorVision::setInputStreams(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream)
	{
		m_leftEyeInputStream = leftEyeStream;
		m_rightEyeInputStream = rightEyeStream;
	}

	void OperatorVision::setOutputStreams(std::shared_ptr<utils::IImageOutputStream> leftEyeStream, std::shared_ptr<utils::IImageOutputStream> rightEyeStream)
	{
		m_leftEyeOutputStream = leftEyeStream;
		m_rightEyeOutputStream = rightEyeStream;
	}

	void OperatorVision::startInputStreaming()
	{
		if (m_leftEyeInputStreamThread.joinable())
		{
			assert(false);
			return;
		}

		m_leftEyeInputStreamThread = std::thread(&OperatorVision::runLeftEyeInputStream, this);
		m_leftEyeInputStreamRequests.push(LeftEyeInputStreamRequest::Start);
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
