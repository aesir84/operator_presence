#include "stdafx.h"

#include "OperatorView.h"

#include "IOperatorViewObserver.h"

namespace operator_view
{
	OperatorView::OperatorView()
		: m_operatorDisplayRenderer(nullptr)
		, m_operatorOculusRiftRenderer(nullptr)
		, m_operatorVisionRenderer(nullptr)
	{ }

	void OperatorView::setRenderingStrategy(std::shared_ptr<IOperatorViewRenderer> renderingStrategy)
	{
		m_renderingStrategy = renderingStrategy;
	}

	void OperatorView::registerObserver(std::shared_ptr<IOperatorViewObserver> observer)
	{
		m_observers.push_back(observer);
	}

	void OperatorView::notifyHeadsetOrientationChanged(double yaw, double pitch, double roll)
	{
		for (auto & observer : m_observers)
		{
			auto existingObserver = observer.lock();

			if (existingObserver)
			{
				existingObserver->updateHeadsetOrientationChanged(yaw, pitch, roll);
			}
		}
	}

	void OperatorView::notifyVisionSelected(std::uint32_t visionId)
	{
		for (auto & observer : m_observers)
		{
			auto existingObserver = observer.lock();

			if (existingObserver)
			{
				existingObserver->updateVisionSelected(visionId);
			}
		}
	}

	void OperatorView::registerOperatorDisplayRenderer(IOperatorDisplayRenderer * operatorDisplayRenderer)
	{
		m_operatorDisplayRenderer = operatorDisplayRenderer;
	}

	void OperatorView::unregisterOperatorDisplayRenderer()
	{
		m_operatorDisplayRenderer = nullptr;
	}

	void OperatorView::registerOperatorOculusRiftRenderer(IOperatorOculusRiftRenderer * operatorOculusRiftRenderer)
	{
		m_operatorOculusRiftRenderer = operatorOculusRiftRenderer;
	}

	void OperatorView::unregisterOperatorOculusRiftRenderer()
	{
		m_operatorOculusRiftRenderer = nullptr;
	}

	void OperatorView::registerOperatorVisionRenderer(IOperatorVisionRenderer * operatorVisionRenderer)
	{
		m_operatorVisionRenderer = operatorVisionRenderer;
	}

	void OperatorView::unregisterOperatorVisionRenderer()
	{
		m_operatorVisionRenderer = nullptr;
	}
}
