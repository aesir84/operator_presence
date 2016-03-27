#include "stdafx.h"

#include "OperatorController.h"

#include "IOperatorModel.h"

#include "IOperatorView.h"
#include "IOperatorViewDevice.h"
#include "IOperatorViewWindow.h"

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
		m_view = operator_view::opengl::Builder(m_model, shared_from_this()).build(operator_view::Builder::DeviceType::Rift);
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
			//
			// TODO : handle the timing
			//

			while (!m_events.empty())
			{
				auto event = m_events.front();
				m_events.pop();

				switch (event)
				{
					case Event::EscapeKeyPressed:
					{
						stopped = true;
					}
					break;
				}
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

	void OperatorController::notifyDeviceOrientationChanged(double yaw, double pitch, double roll)
	{
		m_model->turnHead(yaw, pitch, roll);
	}

	void OperatorController::notifyWindowCreated(std::uint32_t windowId)
	{
		m_device->setWindowId(windowId);
	}
}
