#pragma once

#include "IOperatorVision.h"

namespace operator_model
{
	class IOperatorVisionReader;
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
		class EyeImageReader;

		std::unique_ptr<EyeImageReader> m_leftEyeImageReader;
		std::unique_ptr<EyeImageReader> m_rightEyeImageReader;

	private:
		class EyeImageWriter;

		std::unique_ptr<EyeImageWriter> m_leftEyeImageWriter;
		std::unique_ptr<EyeImageWriter> m_rightEyeImageWriter;

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

