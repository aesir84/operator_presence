#include "stdafx.h"

#include "OperatorViewBuilder.h"

#include "IOperatorDisplayRenderer.h"
#include "IOperatorModel.h"
#include "IOperatorOculusRiftStrategy.h"
#include "IOperatorViewFactory.h"
#include "IOperatorVisionDecorator.h"
#include "OperatorView.h"

namespace operator_view
{
	OperatorViewBuilder::OperatorViewBuilder(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<operator_controller::IOperatorController> controller, std::unique_ptr<IOperatorViewFactory> viewFactory)
		: m_model(model)
		, m_controller(controller)
		, m_viewFactory(std::move(viewFactory))
	{
		//
		// Compose what is a must for the view.
		//

		auto displayRenderer = m_viewFactory->createOperatorDisplayRenderer(m_controller);
		auto visionDecorator = m_viewFactory->createOperatorVisionDecorator(displayRenderer);
		
		m_model->registerObserver(visionDecorator);

		m_viewRenderer = visionDecorator;
	}

	OperatorViewBuilder::~OperatorViewBuilder() = default;

	std::shared_ptr<IOperatorView> OperatorViewBuilder::build(Strategy strategy)
	{
		//
		// Take what has been built so far and apply the requested strategy.
		//

		std::shared_ptr<IOperatorViewStrategy> viewStrategy;

		switch (strategy)
		{
			case Strategy::OculusRift:
			{
				viewStrategy = m_viewFactory->createOperatorOculusRiftStrategy(m_viewRenderer, m_controller);
			}
			break;

			default:
			{
				assert(false);
			}
		}

		// Return the view parametrized with the requested strategy.
		//
		return std::shared_ptr<IOperatorView>(new OperatorView(viewStrategy));
	}
}
