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
		, m_operatorDisplay(nullptr)
		, m_operatorHeadset(nullptr)
		, m_exposedWindowId(0)
		, m_state(ControlState::Initializing)
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
		m_yaw = yaw;
		m_pitch = pitch;
		m_roll = roll;

		control(ControlSignal::HeadOrientationChanged);
	}

	void OperatorController::updateKeyPressed(Qt::Key key)
	{
		m_pressedKey = key;
		control(ControlSignal::KeyPressed);
	}

	void OperatorController::updateWindowExposed(WId windowId)
	{
		m_exposedWindowId = windowId;
		control(ControlSignal::WindowExposed);
	}

	void OperatorController::updateWindowRefreshed()
	{
		control(ControlSignal::WindowRefreshed);
	}

	void OperatorController::updateWindowSizeChanged(std::uint16_t width, std::uint16_t height)
	{
		m_windowWidth = width;
		m_windowHeight = height;

		control(ControlSignal::WindowSizeChanged);
	}

	void OperatorController::control(ControlSignal signal)
	{
		switch (m_state)
		{
			case ControlState::Initializing:
			{
				switch (signal)
				{
					case ControlSignal::WindowExposed:
					{
						// A contract: Before calling this method with this signal ControlSignal::WindowExposed as its argument,
						//             the member m_exposedWindowId must have already been set by the caller.
						//
						assert(m_exposedWindowId != 0);

						m_operatorHeadset->setWindowId(m_exposedWindowId);
						m_view->initialize();
						m_operatorDisplay->refresh();

						m_state = ControlState::Rendering;
					}
					break;

					case ControlSignal::KeyPressed:
					{
						switch (m_pressedKey)
						{
							case Qt::Key_Escape:
							{
								m_state = ControlState::Terminating;
							}
							break;

							default:
							{

							}
						}
					}
					break;

					default:
					{
						// For now let's put an assert here
						// to see how things will operate.
						//
						assert(false);
					}
				}
				
			}
			break;

			case ControlState::Rendering:
			{
				switch (signal)
				{
					case ControlSignal::WindowRefreshed:
					{
						m_view->render();
						m_operatorDisplay->refresh();
					}
					break;

					case ControlSignal::WindowSizeChanged:
					{

					}
					break;

					case ControlSignal::HeadOrientationChanged:
					{
						m_model->turnHead(m_yaw, m_pitch, m_roll);
					}
					break;

					case ControlSignal::KeyPressed:
					{
						switch (m_pressedKey)
						{
							case Qt::Key_Escape:
							{
								m_state = ControlState::Terminating;
							}
							break;

							default:
							{

							}
						}
					}
					break;

					default:
					{
						// For now let's put an assert here
						// to see how things will operate.
						//
						assert(false);
					}
				}
			}
			break;

			case ControlState::Terminating:
			{

			}
			break;

			default:
			{
				assert(false);
			}
		}
	}
}
