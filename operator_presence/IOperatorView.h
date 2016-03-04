#pragma once

namespace operator_view
{
	class IOperatorViewObserver;
	class IOperatorViewRenderer;
}

namespace operator_view
{
	class IOperatorView
	{
	public:
		virtual ~IOperatorView() { }

	private:
		virtual void setRenderingStrategy(std::shared_ptr<IOperatorViewRenderer> renderingStrategy) = 0;

	public:
		virtual void open() = 0;
		virtual void close() = 0;

	public:
		virtual void exec() = 0;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorViewObserver> observer) = 0;

	private:
		virtual void notifyHeadsetOrientationChanged(double yaw, double pitch, double roll) = 0;
		virtual void notifyVisionSelected(std::uint32_t visionId) = 0;
	};
}
