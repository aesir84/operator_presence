#pragma once

#include "OperatorEyeImageType.h"

namespace operator_model
{
	namespace utils
	{
		class IImageOutputStream;
	}
}

namespace operator_model
{
	/// \brief A namespace for internal details of specific classes
	///
	/// This namespace is meant as an alternative to the pimpl idiom.
	/// Therefore, the classes in this namespace are meant for exclusive
	/// use by certain classes. Naturally, the classes in this namespace
	/// have private constructors and the corresponding "master" classes
	/// defined as friends.
	///
	namespace detail
	{
		class OperatorEyeImageWriter
		{
			friend class OperatorVision;

		private:
			OperatorEyeImageWriter();

		public:
			~OperatorEyeImageWriter();

		public:
			using WritingStrategy = std::shared_ptr<utils::IImageOutputStream>;

		public:
			void writeEyeImage(EyeImage eyeImage);

		private:
			bool getAvailableEyeImage(EyeImage & eyeImage);
			void setEyeImage(EyeImage eyeImage);

		private:
			EyeImage m_eyeImage;
			std::atomic<bool> m_eyeImageAvailable;
			std::mutex m_eyeImageGuard;

		public:
			void resetWritingStrategy(WritingStrategy eyeStream);

		private:
			bool getAvailableWritingStrategy(WritingStrategy & writingStrategy);
			void setWritingStrategy(WritingStrategy writingStrategy);

		private:
			WritingStrategy m_writingStrategy;
			std::atomic<bool> m_writingStrategyAvailable;
			std::mutex m_writingStrategyGuard;

		private:
			void startWriting();

		private:
			std::thread m_writingThread;

		private:
			bool isWritingStopped() const { return m_writingStopped; }
			void stopWriting();

		private:
			std::atomic<bool> m_writingStopped;
		};
	}
}
