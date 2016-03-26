#include "stdafx.h"

#include "OperatorController.h"

#include "IOperatorDisplay.h"
#include "IOperatorHeadset.h"
#include "IOperatorModel.h"
#include "IOperatorView.h"

#include "OpenGLOperatorViewBuilder.h"

namespace operator_controller
{
	std::shared_ptr<OperatorController> OperatorController::create(std::shared_ptr<operator_model::IOperatorModel> model)
	{
		auto controller = std::shared_ptr<OperatorController>(new OperatorController(model));
		controller->initializeView();

		return controller;
	}

	OperatorController::OperatorController(std::shared_ptr<operator_model::IOperatorModel> model)
		: m_model(model)
		, m_device(nullptr)
		, m_window(nullptr)
	{ }

	void OperatorController::initializeView()
	{
		m_view = operator_view::opengl::OperatorViewBuilder(m_model, shared_from_this()).build(operator_view::OperatorViewBuilder::Strategy::OculusRift);
	}

	void OperatorController::run()
	{
		m_view->initialize();


		//
		// Run the game loop.
		//

		bool stopped = false;

		while (!stopped)
		{
			while (!m_events.empty())
			{
				switch (m_events.front())
				{
					case Event::EscapeKeyPressed:
					{
						stopped = true;
					}
					break;
				}

				m_events.pop();
			}

			m_view->render();
		}
	}

	void OperatorController::registerDevice(operator_view::IDevice * device)
	{
		m_device = device;
	}

	void OperatorController::registerWindow(operator_view::IWindow * window)
	{
		m_window = window;
	}

	void OperatorController::notifyEscapeKeyPressed()
	{
		m_events.push(Event::EscapeKeyPressed);
	}

	void OperatorController::notifyWindowCreated(std::uint32_t windowId)
	{
		m_device->updateWindowId(windowId);
	}
}
