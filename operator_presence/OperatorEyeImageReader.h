#pragma once

#include "OperatorEyeImageType.h"

namespace operator_model
{
	namespace utils
	{
		class IImageInputStream;
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
		/// \brief A reader for operator eye images
		///
		/// This is a helper class of OperatorVision
		/// which is used to simplify the use of blocking utils::IImageInputStream interface.
		/// In order to hide the details of this reader class and also not to overencumber the main class OperatorVision
		/// this class is designed using the pimpl idiom.
		/// The class uses the Strategy pattern to allow changing
		/// the way the images are read during run-time.
		/// Since the class uses utils::IImageInputStream objects as strategies,
		/// and the latter ones are synchronous, therefore, the class utilizes
		/// threads to run these strategies.
		///
		class OperatorEyeImageReader
		{
			friend class OperatorVision;

		public:
			using OperatorVisionCallbackPtr = void(OperatorVision::*)(EyeImage);

		private:
			OperatorEyeImageReader(OperatorVision & operatorVision, OperatorVisionCallbackPtr callback);

		private:
			OperatorVision & m_operatorVision;
			OperatorVisionCallbackPtr m_callback;

		public:
			~OperatorEyeImageReader();

		public:
			using ReadingStrategy = std::shared_ptr<utils::IImageInputStream>;

		public:
			/// \brief A method to start/control the reading strategy
			///
			/// This method is the main entrypoint of the interface of this class.
			/// Therefore, it combines two use cases of this class:
			///
			/// 1. starts the reading thread with the specified strategy
			/// 2. replaces the old strategy by the new one if the thread is already running
			///
			/// Keep in mind that if this method is never called then no threads will be run.
			///
			void resetReadingStrategy(ReadingStrategy eyeStream);

		private:
			bool getAvailableReadingStrategy(ReadingStrategy & readingStrategy);
			void setReadingStrategy(ReadingStrategy readingStrategy);

		private:
			ReadingStrategy m_readingStrategy;
			std::atomic<bool> m_readingStrategyAvailable;
			std::mutex m_readingStrategyGuard;

		private:
			void startReading();

		private:
			std::thread m_readingThread;

		private:
			bool isReadingStopped() const { return m_readingStopped; }
			void stopReading();

		private:
			std::atomic<bool> m_readingStopped;
		};
	}
}
