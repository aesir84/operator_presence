#include "stdafx.h"

#include "OperatorView.h"

#include "IOperatorViewStrategy.h"

namespace operator_view
{
	OperatorView::OperatorView(std::shared_ptr<IOperatorViewStrategy> viewStrategy)
		: m_viewStrategy(viewStrategy)
	{ }

	void OperatorView::initialize()
	{
		m_viewStrategy->initialize();
	}

	void OperatorView::render()
	{
		m_viewStrategy->render();
	}
}
