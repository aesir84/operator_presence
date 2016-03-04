#include "stdafx.h"

#include "OperatorViewBuilder.h"

#include "IOperatorModel.h"

#include "IOperatorRendererFactory.h"

#include "IOperatorDisplayRenderer.h"
#include "IOperatorVisionRenderer.h"

#include "IOperatorViewRendererFactory.h"

#include "IOperatorOculusRiftRenderer.h"

#include "OperatorView.h"

namespace operator_view
{
	OperatorViewBuilder::OperatorViewBuilder(std::shared_ptr<operator_model::IOperatorModel> operatorModel, std::unique_ptr<IOperatorViewRendererFactory> operatorViewRendererFactory, std::unique_ptr<IOperatorRendererFactory> operatorRendererFactory)
		: m_operatorModel(operatorModel)
		, m_operatorViewRendererFactory(std::move(operatorViewRendererFactory))
		, m_operatorRendererFactory(std::move(operatorRendererFactory))
		, m_operatorViewBuilt(false)
	{
		m_operatorView = std::shared_ptr<OperatorView>(new OperatorView);

		auto operatorDisplayRenderer = m_operatorRendererFactory->createOperatorDisplayRenderer(m_operatorView);
		auto operatorVisionRenderer = m_operatorRendererFactory->createOperatorVisionRenderer(operatorDisplayRenderer, m_operatorView);
		
		m_operatorModel->registerObserver(operatorVisionRenderer);
		m_operatorRenderer = operatorVisionRenderer;
	}

	void OperatorViewBuilder::displayHUD()
	{
		/* not yet implemented */
	}

	std::shared_ptr<IOperatorView> OperatorViewBuilder::build()
	{
		if (m_operatorViewBuilt)
		{
			assert(false); return m_operatorView;
		}

		auto operatorOculusRiftRenderer = m_operatorViewRendererFactory->createOperatorOculusRiftRenderer(m_operatorRenderer, m_operatorView);
		m_operatorView->setRenderingStrategy(operatorOculusRiftRenderer);

		m_operatorViewBuilt = true;

		return m_operatorView;
	}
}
