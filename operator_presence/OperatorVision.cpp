#include "stdafx.h"

#include "OperatorVision.h"

#include "IImageInputStream.h"
#include "IOperatorVisionObserver.h"
#include "threadsafe_queue.h"

namespace operator_model
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
	class OperatorVision::EyeImageReader
	{
		friend class OperatorVision;

	private:
		using CallbackPtr = void(OperatorVision::*)(EyeImage);

	private:
		EyeImageReader(OperatorVision & operatorVision, CallbackPtr callback)
			: m_operatorVision(operatorVision)
			, m_callback(callback)
		{ }

	public:
		~EyeImageReader()
		{
			if (m_streamingThread.joinable())
			{
				m_streamingStrategyResets.push(nullptr);
				m_streamingThread.join();
			}
		}

	private:
		OperatorVision & m_operatorVision;
		CallbackPtr m_callback;

	private:
		/// \brief A nethod to start/control the reading strategy
		///
		/// This method is the main entrypoint of the interface of this class.
		/// Therefore, it combines two use cases of this class:
		/// 1. starts the reading threads with the specified strategy
		/// 2. replaces the old strategy by the new one if the threads are already running
		/// Keep in mind that if this method is never called then no threads will be run.
		///
		void resetStreamingStrategy(std::shared_ptr<utils::IImageInputStream> eyeStream)
		{
			m_streamingStrategyResets.push(eyeStream);

			if (!m_streamingThread.joinable())
			{
				m_streamingThread = std::thread(&EyeImageReader::stream, this);
			}
		}

	private:
		helpers::threadsafe_queue<std::shared_ptr<utils::IImageInputStream>> m_streamingStrategyResets;

	private:
		enum class StreamingState { Resetting, Streaming, Exiting };

	private:
		void stream()
		{
			StreamingState state = StreamingState::Resetting;

			std::shared_ptr<utils::IImageInputStream> currentStreamingStrategy = nullptr;
			std::shared_ptr<utils::IImageInputStream> nextStreamingStrategy = nullptr;

			do
			{
				m_streamingStrategyResets.wait_and_pop(nextStreamingStrategy);

				switch (state)
				{
				case StreamingState::Resetting:
				{
					if (nextStreamingStrategy == nullptr)
					{
						state = StreamingState::Exiting;
					}
					else
					{
						currentStreamingStrategy = nextStreamingStrategy;
						state = StreamingState::Streaming;
					}
				}
				break;

				case StreamingState::Streaming:
				{
					if (nextStreamingStrategy != currentStreamingStrategy)
					{
						state = StreamingState::Resetting;
					}
					else
					{
						assert(currentStreamingStrategy != nullptr);

						(m_operatorVision.*m_callback)(currentStreamingStrategy->read());
						m_streamingStrategyResets.wait_and_pop(currentStreamingStrategy);
					}
				}
				break;
				}

			} while (state != StreamingState::Exiting);
		}

	private:
		std::thread m_streamingThread;
	};

	class OperatorVision::EyeImageWriter
	{
	public:
		~EyeImageWriter()
		{ }
	};

	OperatorVision::OperatorVision()
		: m_leftEyeImageReader(std::unique_ptr<EyeImageReader>(new EyeImageReader(*this, &OperatorVision::updateLeftEyeImage)))
		, m_rightEyeImageReader(std::unique_ptr<EyeImageReader>(new EyeImageReader(*this, &OperatorVision::updateRightEyeImage)))
	{ }

	void OperatorVision::setInputStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream)
	{
		m_leftEyeImageReader->resetStreamingStrategy(leftEyeStream);
		m_rightEyeImageReader->resetStreamingStrategy(rightEyeStream);
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
