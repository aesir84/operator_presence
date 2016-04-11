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
			m_view->render();

			// After the rendering has been performed, handle the events.
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

					case Event::WindowSizeChanged:
					{
						m_device->resize(m_windowWidth, m_windowHeight);
					}
					break;
				}
			}
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

	void OperatorController::notifyWindowSizeChanged(std::uint16_t width, std::uint16_t height)
	{
		m_windowWidth = width;
		m_windowHeight = height;

		m_events.push(Event::WindowSizeChanged);
	}
}
