#include "stdafx.h"

#include "OperatorViewBuilder.h"

#include "IOperatorDisplayRenderer.h"
#include "IOperatorModel.h"
#include "IOperatorViewFactory.h"
#include "IOperatorVisionDecorator.h"

namespace operator_view
{
	OperatorViewBuilder::OperatorViewBuilder(std::shared_ptr<operator_model::IOperatorModel> operatorModel, std::unique_ptr<IOperatorViewFactory> operatorViewFactory)
		: m_operatorModel(operatorModel)
		, m_operatorViewFactory(std::move(operatorViewFactory))
	{
		//
		// Compose what is a must for the view.
		//

		auto operatorDisplayRenderer = m_operatorViewFactory->createOperatorDisplayRenderer();
		auto operatorVisionDecorator = m_operatorViewFactory->createOperatorVisionDecorator(operatorDisplayRenderer);
		
		m_operatorModel->registerObserver(operatorVisionDecorator);

		m_renderer = operatorVisionDecorator;
	}

	std::shared_ptr<IOperatorView> OperatorViewBuilder::build(Strategy strategy)
	{
		// Take what has been built so far and apply the requested strategy.
		//
		switch (strategy)
		{
			case Strategy::OculusRift:
			{
				auto operatorViewStrategy = m_cachedOperatorOculusRiftStrategy.lock();

				if (operatorViewStrategy == nullptr)
				{
					operatorViewStrategy = m_operatorViewFactory->createOperatorOculusRiftStrategy(m_renderer);
					m_cachedOperatorOculusRiftStrategy = operatorViewStrategy;
				}
			}
			break;

			default:
			{
				assert(false);
			}
		}
	}
}
