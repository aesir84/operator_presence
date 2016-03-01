#include "stdafx.h"

#include "OperatorVision.h"

#include "IImageInputStream.h"
#include "IOperatorVisionObserver.h"
#include "threadsafe_queue.h"

namespace operator_model
{
	/// \brief An updater of operator eye images
	///
	/// This is a helper class of OperatorVision
	/// which is used to simplify the use of blocking utils::IImageInputStream interface.
	/// In order to hide the details of this updater class and also not to overencumber the main class OperatorVision
	/// this class is designed using the pimpl idiom.
	/// The class uses the Strategy pattern to allow changing
	/// the way the images are updated during run-time.
	/// Since the class uses utils::IImageInputStream objects as a strategy,
	/// and the latter one is synchronous, therefore, the class utilizes
	/// a thread to run the strategy.
	///
	class OperatorVision::EyeImageUpdater
	{
	public:
		using UpdateCallbackPtr = void(OperatorVision::*)(EyeImage);

	public:
		EyeImageUpdater(OperatorVision & vision, UpdateCallbackPtr update)
			: m_vision(vision)
			, m_update(update)
		{ }

		~EyeImageUpdater()
		{
			stopUpdating();
		}

	private:
		OperatorVision & m_vision;
		UpdateCallbackPtr m_update;

	public:
		using UpdatingStrategy = std::shared_ptr<utils::IImageInputStream>;

	public:
		void setUpdatingStrategy(UpdatingStrategy strategy)
		{
			setStrategy(strategy);

			if (!m_updatingThread.joinable())
			{
				m_updatingThread = std::thread(&EyeImageUpdater::update, this);
			}
		}

	private:
		bool getAvailableStrategy(UpdatingStrategy & strategy)
		{
			if (!m_updatingStrategyAvailable)
			{
				return false;
			}

			std::lock_guard<std::mutex> lock(m_updatingStrategyGuard);

			strategy = m_updatingStrategy;
			m_updatingStrategyAvailable = false;

			return true;
		}

		void setStrategy(UpdatingStrategy strategy)
		{
			std::lock_guard<std::mutex> lock(m_updatingStrategyGuard);
			m_updatingStrategy = strategy;
			m_updatingStrategyAvailable = true;
		}

	private:
		UpdatingStrategy m_updatingStrategy;
		std::atomic<bool> m_updatingStrategyAvailable;
		std::mutex m_updatingStrategyGuard;

	private:
		void update()
		{
			UpdatingStrategy strategy;

			while (!m_updatingStopped)
			{
				getAvailableStrategy(strategy); assert(strategy);
				(m_vision.*m_update)(strategy->read());
			}
		}

	private:
		std::thread m_updatingThread;

	private:
		void stopUpdating()
		{
			if (m_updatingThread.joinable())
			{
				m_updatingStopped = true;
				m_updatingThread.join();
			}
		}

	private:
		std::atomic<bool> m_updatingStopped;
	};

	OperatorVision::OperatorVision()
		: m_leftEyeImageUpdater(std::make_unique<EyeImageUpdater>(*this, &OperatorVision::updateLeftEyeImage))
		, m_rightEyeImageUpdater(std::make_unique<EyeImageUpdater>(*this, &OperatorVision::updateRightEyeImage))
	{ }

	void OperatorVision::setUpdateStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream)
	{
		m_leftEyeImageUpdater->setUpdatingStrategy(leftEyeStream);
		m_rightEyeImageUpdater->setUpdatingStrategy(rightEyeStream);
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
