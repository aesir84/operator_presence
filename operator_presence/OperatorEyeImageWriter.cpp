#include "stdafx.h"

#include "OperatorEyeImageWriter.h"

#include "IImageOutputStream.h"

namespace operator_model
{
	namespace detail
	{
		OperatorEyeImageWriter::OperatorEyeImageWriter()
			: m_writingStopped(false)
			, m_writingStrategyAvailable(false)
			, m_eyeImageAvailable(false)
		{ }

		OperatorEyeImageWriter::~OperatorEyeImageWriter()
		{
			stopWriting();
		}

		void OperatorEyeImageWriter::writeEyeImage(EyeImage eyeImage)
		{
			setEyeImage(eyeImage);
		}

		bool OperatorEyeImageWriter::getAvailableEyeImage(EyeImage & eyeImage)
		{
			if (!m_eyeImageAvailable)
			{
				return false;
			}

			std::lock_guard<std::mutex> lock(m_eyeImageGuard);

			eyeImage = m_eyeImage;
			m_eyeImageAvailable = false;

			return true;
		}

		void OperatorEyeImageWriter::setEyeImage(EyeImage eyeImage)
		{
			std::lock_guard<std::mutex> lock(m_eyeImageGuard);

			m_eyeImage = eyeImage;
			m_eyeImageAvailable = true;
		}

		void OperatorEyeImageWriter::resetWritingStrategy(WritingStrategy eyeStream)
		{
			setWritingStrategy(eyeStream);

			if (!m_writingThread.joinable())
			{
				m_writingThread = std::thread(&OperatorEyeImageWriter::startWriting, this);
			}
		}

		bool OperatorEyeImageWriter::getAvailableWritingStrategy(WritingStrategy & writingStrategy)
		{
			if (!m_writingStrategyAvailable)
			{
				return false;
			}

			std::lock_guard<std::mutex> lock(m_writingStrategyGuard);

			writingStrategy = m_writingStrategy;
			m_writingStrategyAvailable = false;

			return true;
		}

		void OperatorEyeImageWriter::setWritingStrategy(WritingStrategy writingStrategy)
		{
			std::lock_guard<std::mutex> lock(m_writingStrategyGuard);

			m_writingStrategy = writingStrategy;
			m_writingStrategyAvailable = true;
		}

		void OperatorEyeImageWriter::startWriting()
		{
			EyeImage eyeImage;
			WritingStrategy writingStrategy;

			while (!isWritingStopped())
			{
				if (getAvailableEyeImage(eyeImage))
				{
					getAvailableWritingStrategy(writingStrategy); assert(writingStrategy);
					writingStrategy->write(eyeImage);
				}
			}
		}

		void OperatorEyeImageWriter::stopWriting()
		{
			if (m_writingThread.joinable())
			{
				m_writingStopped = true;
				m_writingThread.join();
			}
		}
	}
}
