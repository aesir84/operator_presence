#include "stdafx.h"

#include "OperatorController.h"

#include "IOperatorModel.h"

#include "IOperatorView.h"
#include "IOperatorViewDevice.h"
#include "IOperatorViewVision.h"
#include "IOperatorViewWindow.h"

#include "OperatorModelBuilder.h"
#include "OpenGLOperatorViewBuilder.h"

namespace operator_controller
{
	std::shared_ptr<OperatorController> OperatorController::create()
	{
		auto controller = std::shared_ptr<OperatorController>(new OperatorController);

		controller->initializeModel();
		controller->initializeView();

		return controller;
	}

	OperatorController::OperatorController()
	{ }

	void OperatorController::initializeModel()
	{
		m_model = operator_model::Builder(shared_from_this()).build();
	}

	void OperatorController::initializeView()
	{
		m_view = operator_view::opengl::Builder(shared_from_this()).build(operator_view::Builder::DeviceType::Rift);
	}

	void OperatorController::run()
	{
		m_view->initialize();

		while (!m_controllerStopped)
		{
			handleModelEvents();
			m_view->render();
			handleViewEvents();
		}
	}

	void OperatorController::registerVision(operator_model::IVision * vision)
	{
		m_modelVision = vision;
	}

	void OperatorController::notifyLeftEyeImageUpdated(operator_model::EyeImage leftEyeImage)
	{
		std::lock_guard<std::mutex> lock(m_eyeImagesGuard);

		m_leftEyeImage = leftEyeImage;
		m_leftEyeImageUpdated = true;
	}

	void OperatorController::notifyRightEyeImageUpdated(operator_model::EyeImage rightEyeImage)
	{
		std::lock_guard<std::mutex> lock(m_eyeImagesGuard);

		m_rightEyeImage = rightEyeImage;
		m_rightEyeImageUpdated = true;
	}

	void OperatorController::handleModelEvents()
	{
		if (m_leftEyeImageUpdated && m_rightEyeImageUpdated)
		{
			std::lock_guard<std::mutex> lock(m_eyeImagesGuard);

			m_viewVision->updateLeftEyeImage(m_leftEyeImage);
			m_viewVision->updateRightEyeImage(m_rightEyeImage);

			m_leftEyeImageUpdated = false;
			m_rightEyeImageUpdated = false;
		}
	}

	void OperatorController::registerDevice(operator_view::IDevice * device)
	{
		m_viewDevice = device;
	}

	void OperatorController::registerVision(operator_view::IVision * vision)
	{
		m_viewVision = vision;
	}

	void OperatorController::registerWindow(operator_view::IWindow * window)
	{
		m_viewWindow = window;
	}

	void OperatorController::notifyEscapeKeyPressed()
	{
		m_viewEvents.push(ViewEvent::EscapeKeyPressed);
	}

	void OperatorController::notifyDeviceOrientationChanged(double yaw, double pitch, double roll)
	{
		m_model->turnHead(yaw, pitch, roll);
	}

	void OperatorController::notifyWindowSizeChanged(std::uint16_t width, std::uint16_t height)
	{
		m_windowWidth = width;
		m_windowHeight = height;

		m_viewEvents.push(ViewEvent::WindowSizeChanged);
	}

	void OperatorController::handleViewEvents()
	{
		while (!m_viewEvents.empty())
		{
			auto event = m_viewEvents.front();
			m_viewEvents.pop();

			switch (event)
			{
				case ViewEvent::EscapeKeyPressed:
				{
					m_controllerStopped = true;
				}
				break;

				case ViewEvent::WindowSizeChanged:
				{
					m_viewDevice->resize(m_windowWidth, m_windowHeight);
				}
				break;
			}
		}
	}
}
