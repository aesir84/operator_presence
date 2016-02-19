#pragma once

namespace operator_model
{
	namespace utils
	{
		class IImageInputStream;
	}
}

namespace operator_model
{
	class IStreamableOperatorVision
	{
	public:
		virtual ~IStreamableOperatorVision() { }

	public:
		virtual void setLeftEyeInputStream(std::shared_ptr<utils::IImageInputStream> stream) = 0;
		virtual void setRightEyeInputStream(std::shared_ptr<utils::IImageInputStream> stream) = 0;

	public:
		virtual void startLeftEyeStreaming() = 0;
		virtual void stopLeftEyeStreaming() = 0;

		virtual void startRightEyeStreaming() = 0;
		virtual void stopRightEyeStreaming() = 0;
	};
}
