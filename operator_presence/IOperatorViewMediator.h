#pragma once

namespace operator_view
{
	class IOperatorDisplayRenderer;
	class IOperatorOculusRiftRenderer;
	class IOperatorVisionRenderer;
}

namespace operator_view
{
	class IOperatorViewMediator
	{
	public:
		virtual ~IOperatorViewMediator() { }

	public:
		virtual void registerOperatorDisplayRenderer(IOperatorDisplayRenderer * operatorDisplayRenderer) = 0;
		virtual void unregisterOperatorDisplayRenderer() = 0;

		virtual void registerOperatorOculusRiftRenderer(IOperatorOculusRiftRenderer * operatorOculusRiftRenderer) = 0;
		virtual void unregisterOperatorOculusRiftRenderer() = 0;

		virtual void registerOperatorVisionRenderer(IOperatorVisionRenderer * operatorVisionRenderer) = 0;
		virtual void unregisterOperatorVisionRenderer() = 0;

	public:
		virtual void mediateKeyPressed(Qt::Key key) = 0;
		virtual void mediateHeadsetOrientationChanged(double yaw, double pitch, double roll) = 0;
		virtual void mediateDisplaySizeChanged(std::uint16_t newWidth, std::uint16_t newHeight) = 0;
	};
}
