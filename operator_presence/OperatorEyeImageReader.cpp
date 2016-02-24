#include "stdafx.h"

#include "OperatorEyeImageReader.h"

#include "IImageInputStream.h"

namespace operator_model
{
	namespace detail
	{
		OperatorEyeImageReader::OperatorEyeImageReader(OperatorVision & operatorVision, OperatorVisionCallbackPtr callback)
			: m_operatorVision(operatorVision)
			, m_callback(callback)
		{ }

		OperatorEyeImageReader::~OperatorEyeImageReader()
		{
			stopReading();
		}

		void OperatorEyeImageReader::resetReadingStrategy(ReadingStrategy eyeStream)
		{
			setReadingStrategy(eyeStream);

			if (!m_readingThread.joinable())
			{
				m_readingThread = std::thread(&OperatorEyeImageReader::startReading, this);
			}
		}

		bool OperatorEyeImageReader::getAvailableReadingStrategy(ReadingStrategy & readingStrategy)
		{
			if (!m_readingStrategyAvailable)
			{
				return false;
			}

			std::lock_guard<std::mutex> lock(m_readingStrategyGuard);

			readingStrategy = m_readingStrategy;
			m_readingStrategyAvailable = false;

			return true;
		}

		void OperatorEyeImageReader::setReadingStrategy(ReadingStrategy readingStrategy)
		{
			std::lock_guard<std::mutex> lock(m_readingStrategyGuard);
			m_readingStrategy = readingStrategy;
			m_readingStrategyAvailable = true;
		}

		void OperatorEyeImageReader::startReading()
		{
			std::shared_ptr<utils::IImageInputStream> readingStrategy;

			while (!isReadingStopped())
			{
				getAvailableReadingStrategy(readingStrategy); assert(readingStrategy);
				(m_operatorVision.*m_callback)(readingStrategy->read());
			}
		}

		void OperatorEyeImageReader::stopReading()
		{
			if (!m_readingStopped)
			{
				m_readingStopped = true;
				m_readingThread.join();
			}
		}
	}
}
