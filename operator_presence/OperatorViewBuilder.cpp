#include "stdafx.h"

#include "OperatorViewBuilder.h"

#include "IOperatorDisplayRenderer.h"
#include "IOperatorModel.h"
#include "IOperatorOculusRiftRenderer.h"
#include "IOperatorRendererFactory.h"
#include "IOperatorVisionRenderer.h"

namespace operator_view
{
	OperatorViewBuilder::OperatorViewBuilder(std::unique_ptr<IOperatorRendererFactory> factory)
		: m_factory(std::move(factory))
	{ }

	std::shared_ptr<IOperatorView> OperatorViewBuilder::build(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<IOperatorViewObserver> observer)
	{
		auto operatorDisplayRenderer = m_factory->createOperatorDisplayRenderer();
		operatorDisplayRenderer->registerObserver(observer);

		auto operatorVisionRenderer = m_factory->createOperatorVisionRenderer(operatorDisplayRenderer);
		model->registerObserver(operatorVisionRenderer);

		auto operatorOculusRiftRenderer = m_factory->createOperatorOculusRiftRenderer(operatorVisionRenderer);
		operatorOculusRiftRenderer->registerObserver(observer);

		return operatorOculusRiftRenderer;
	}
}
