#include "stdafx.h"

#include "OperatorView.h"

#include "IOperatorViewDevice.h"

namespace operator_view
{
	OperatorView::OperatorView(std::shared_ptr<IDevice> device)
		: m_device(device)
	{ }

	void OperatorView::initialize()
	{
		m_device->initialize();
	}

	void OperatorView::render()
	{
		m_device->render();
	}
}
