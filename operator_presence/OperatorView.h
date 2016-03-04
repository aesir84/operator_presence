#pragma once

#include "IOperatorView.h"
#include "IOperatorViewMediator.h"

namespace operator_view
{
	class OperatorView : public IOperatorView, public IOperatorViewMediator
	{
		friend class OperatorViewBuilder;

	private:
		OperatorView();

	private:
		virtual void setRenderingStrategy(std::shared_ptr<IOperatorViewRenderer> renderingStrategy) override;

	private:
		virtual void open() override;
		virtual void close() override;

	private:
		virtual void exec() override;

	private:
		virtual void registerObserver(std::shared_ptr<IOperatorViewObserver> observer) override;

	private:
		virtual void notifyHeadsetOrientationChanged(double yaw, double pitch, double roll) override;
		virtual void notifyVisionSelected(std::uint32_t visionId) override;

	private:
		virtual void registerOperatorDisplayRenderer(IOperatorDisplayRenderer * operatorDisplayRenderer) override;
		virtual void unregisterOperatorDisplayRenderer() override;

		virtual void registerOperatorOculusRiftRenderer(IOperatorOculusRiftRenderer * operatorOculusRiftRenderer) override;
		virtual void unregisterOperatorOculusRiftRenderer() override;

		virtual void registerOperatorVisionRenderer(IOperatorVisionRenderer * operatorVisionRenderer) override;
		virtual void unregisterOperatorVisionRenderer() override;

	private:
		IOperatorDisplayRenderer * m_operatorDisplayRenderer;
		IOperatorOculusRiftRenderer * m_operatorOculusRiftRenderer;
		IOperatorVisionRenderer * m_operatorVisionRenderer;

	private:
		virtual void mediateKeyPressed(Qt::Key key) override;
		virtual void mediateHeadsetOrientationChanged(double yaw, double pitch, double roll) override;
		virtual void mediateDisplaySizeChanged(std::uint16_t newWidth, std::uint16_t newHeight) override;
	};
}
