#pragma once

#include "IOperatorVision.h"

namespace operator_model
{
	namespace detail
	{
		class OperatorEyeImageReader;
		class OperatorEyeImageWriter;
	}
}

namespace operator_model
{
	class OperatorVision : public IOperatorVision
	{
	public:
		OperatorVision();

	public:
		virtual void setInputStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream) override;
		virtual void setOutputStrategy(std::shared_ptr<utils::IImageOutputStream> leftEyeStream, std::shared_ptr<utils::IImageOutputStream> rightEyeStream) override;

	private:
		std::unique_ptr<detail::OperatorEyeImageReader> m_leftEyeImageReader;
		std::unique_ptr<detail::OperatorEyeImageReader> m_rightEyeImageReader;

	private:
		std::unique_ptr<detail::OperatorEyeImageWriter> m_leftEyeImageWriter;
		std::unique_ptr<detail::OperatorEyeImageWriter> m_rightEyeImageWriter;

	private:
		void updateLeftEyeImage(EyeImage eyeImage);
		void updateRightEyeImage(EyeImage eyeImage);

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) override;

	private:
		virtual void notifyLeftEyeImageChanged(EyeImage leftEyeImage) override;
		virtual void notifyRightEyeImageChanged(EyeImage rightEyeImage) override;

	private:
		std::vector<std::weak_ptr<IOperatorVisionObserver>> m_observers;
	};
}

