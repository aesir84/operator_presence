#include "stdafx.h"

#include "OperatorController.h"

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
		, m_operatorDisplay(nullptr)
		, m_operatorHeadset(nullptr)
	{ }

	void OperatorController::initializeView()
	{
		m_view = operator_view::opengl::OperatorViewBuilder(m_model, shared_from_this()).build(operator_view::OperatorViewBuilder::Strategy::OculusRift);
	}

	void OperatorController::registerOperatorDisplay(IOperatorDisplay * operatorDisplay)
	{
		m_operatorDisplay = operatorDisplay;
	}

	void OperatorController::registerOperatorHeadset(IOperatorHeadset * operatorHeadset)
	{
		m_operatorHeadset = operatorHeadset;
	}

	void OperatorController::updateHeadsetOrientationChanged(double yaw, double pitch, double roll)
	{
		m_model->turnHead(yaw, pitch, roll);
	}

	void OperatorController::updateKeyPressed(Qt::Key key)
	{
		// TODO: corresponding UI logic goes here
	}

	void OperatorController::updateWindowExposed(WId windowId)
	{
		// TODO: corresponding UI logic goes here
	}

	void OperatorController::updateWindowSizeChanged(std::uint16_t width, std::uint16_t height)
	{
		// TODO: corresponding UI logic goes here
	}
}
