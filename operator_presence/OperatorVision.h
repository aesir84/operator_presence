#pragma once

#include "IObservableOperatorVision.h"
#include "IStreamableOperatorVision.h"

#include "threadsafe_queue.h"

namespace operator_model
{
	class OperatorVision : public IObservableOperatorVision, public IStreamableOperatorVision
	{
	public:
		OperatorVision();

	public:
		virtual void setInputStreams(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream) override;
		virtual void setOutputStreams(std::shared_ptr<utils::IImageOutputStream> leftEyeStream, std::shared_ptr<utils::IImageOutputStream> rightEyeStream) override;

	private:
		std::shared_ptr<utils::IImageInputStream> m_leftEyeInputStream;
		std::shared_ptr<utils::IImageInputStream> m_rightEyeInputStream;

		std::shared_ptr<utils::IImageOutputStream> m_leftEyeOutputStream;
		std::shared_ptr<utils::IImageOutputStream> m_rightEyeOutputStream;

	public:
		virtual void startInputStreaming() override;
		virtual void stopInputStreaming() override;

	private:
		enum class LeftEyeInputStreamRequest { Start, Stop };
		enum class RightEyeInputStreamRequest { Start, Stop };

	private:
		helpers::threadsafe_queue<LeftEyeInputStreamRequest> m_leftEyeInputStreamRequests;
		helpers::threadsafe_queue<RightEyeInputStreamRequest> m_rightEyeInputStreamRequests;

	private:
		void runLeftEyeInputStream();
		void runRightEyeInputStream();

	private:
		std::thread m_leftEyeInputStreamThread;
		std::thread m_rightEyeInputStreamThread;

	public:
		virtual void startOutputStreaming() override;
		virtual void stopOutputStreaming() override;

	private:
		enum class LeftEyeOutputStreamRequest { Start, Stop };
		enum class RightEyeOutputStreamRequest { Start, Stop };
	
	private:
		helpers::threadsafe_queue<LeftEyeOutputStreamRequest> m_leftEyeOutputStreamRequests;
		helpers::threadsafe_queue<RightEyeOutputStreamRequest> m_rightEyeOutputStreamRequests;
		
	private:
		void runLeftEyeOutputStream();
		void runRightEyeOutputStream();

	private:
		EyeImage m_leftEyeImage;
		EyeImage m_rightEyeImage;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) override;

	private:
		virtual void notifyLeftEyeImageChanged(EyeImage leftEyeImage) override;
		virtual void notifyRightEyeImageChanged(EyeImage rightEyeImage) override;

	private:
		std::vector<std::weak_ptr<IOperatorVisionObserver>> m_observers;
	};
}

