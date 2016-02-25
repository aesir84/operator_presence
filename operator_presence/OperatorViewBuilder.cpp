#include "stdafx.h"

#include "OperatorViewBuilder.h"

#include "IOperatorModel.h"

#include "IOperatorDisplayRenderer.h"
#include "IOperatorOculusRiftRenderer.h"
#include "IOperatorRendererFactory.h"
#include "IOperatorVisionRenderer.h"

namespace operator_view
{
	OperatorViewBuilder::OperatorViewBuilder(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<IOperatorViewObserver> observer, std::unique_ptr<IOperatorRendererFactory> factory)
		: m_model(model)
		, m_observer(observer)
		, m_factory(std::move(factory))
	{
		auto operatorDisplayRenderer = m_factory->createOperatorDisplayRenderer();
		operatorDisplayRenderer->registerObserver(m_observer);

		auto operatorVisionRenderer = m_factory->createOperatorVisionRenderer(operatorDisplayRenderer);
		m_model->registerObserver(operatorVisionRenderer);

		m_renderer = operatorVisionRenderer;
	}

	void OperatorViewBuilder::displayHUD()
	{
		/* not implemented */
	}

	std::shared_ptr<IOperatorView> OperatorViewBuilder::build()
	{
		auto operatorOculusRiftRenderer = m_factory->createOperatorOculusRiftRenderer(m_renderer);
		operatorOculusRiftRenderer->registerObserver(m_observer);

		return operatorOculusRiftRenderer;
	}
}
