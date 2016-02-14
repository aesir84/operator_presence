#pragma once

#include "IOperatorVision.h"

namespace operator_model
{
	class OperatorVision : public IOperatorVision
	{
	public:
		OperatorVision();

	public:
		/// \brief Image input strategy setters
		///
		/// \pre the corresponding strategies are not executing at the same time
		/// \param a strategy for input streaming the images
		///
		virtual void setLeftEyeInputStream(std::shared_ptr<utils::IImageInputStream> stream) override;
		virtual void setRightEyeInputStream(std::shared_ptr<utils::IImageInputStream> stream) override;

	private:
		std::shared_ptr<utils::IImageInputStream> m_leftEyeInputStream;
		std::shared_ptr<utils::IImageInputStream> m_rightEyeInputStream;

	public:
		/// \brief Left eye input streaming start
		///
		/// This method is blocking, thus, the client should run it in a separate thread.
		///
		virtual void startLeftEyeStreaming() override;

		/// \brief Left eye input streaming stop
		///
		/// \pre left eye input streaming is currently running
		/// The method tells the running input streaming to stop and returns.
		///
		virtual void stopLeftEyeStreaming() override;

		/// \brief Right eye input streaming start
		///
		/// This method is blocking, thus, the client should run it in a separate thread.
		///
		virtual void startRightEyeStreaming() override;

		/// \brief Right eye input streaming stop
		///
		/// \pre right eye input streaming is currently running
		/// The method tells the running input streaming to stop and returns.
		///
		virtual void stopRightEyeStreaming() override;

	private:
		std::atomic<bool> m_leftEyeInputStreamingStopped;
		std::atomic<bool> m_rightEyeInputStreamingStopped;

	private:
		std::shared_ptr<QImage> m_leftEyeImage;
		std::shared_ptr<QImage> m_rightEyeImage;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) override;

	private:
		virtual void notifyLeftEyeImageChanged(std::shared_ptr<QImage> leftEyeImage) override;
		virtual void notifyRightEyeImageChanged(std::shared_ptr<QImage> rightEyeImage) override;

	private:
		std::vector<std::weak_ptr<IOperatorVisionObserver>> m_observers;
	};
}

