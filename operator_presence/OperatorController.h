#pragma once

#include "IOperatorController.h"

namespace operator_model
{
	class IOperatorModel;
}

namespace operator_view
{
	class IOperatorView;
}

namespace operator_controller
{
	class OperatorController : public IOperatorController, public std::enable_shared_from_this<OperatorController>
	{
	public:
		static std::shared_ptr<OperatorController> create(std::shared_ptr<operator_model::IOperatorModel> model);

	private:
		OperatorController(std::shared_ptr<operator_model::IOperatorModel> model);

	private:
		void initializeView();

	private:
		std::shared_ptr<operator_model::IOperatorModel> m_model;
		std::shared_ptr<operator_view::IOperatorView> m_view;

	private:
		virtual void registerOperatorDisplay(IOperatorDisplay * operatorDisplay) override;
		virtual void registerOperatorHeadset(IOperatorHeadset * operatorHeadset) override;

	private:
		IOperatorDisplay * m_operatorDisplay;
		IOperatorHeadset * m_operatorHeadset;

	private:
		/// \brief Overriden mediator interface methods
		///
		/// These methods serve as a gateway to the main routine of this controller, control() method.
		/// Therefore, their only tasks are:
		/// 1. save any passed parameters to the corresponding fields in the object
		/// 2. delegate the correct signal to the control() method
		///
		virtual void updateHeadsetOrientationChanged(double yaw, double pitch, double roll) override;
		virtual void updateKeyPressed(Qt::Key key) override;
		virtual void updateWindowExposed(WId windowId) override;
		virtual void updateWindowRefreshed() override;
		virtual void updateWindowSizeChanged(std::uint16_t width, std::uint16_t height) override;

	private:
		double m_yaw;
		double m_pitch;
		double m_roll;

		WId m_exposedWindowId;
		Qt::Key m_pressedKey;

		std::uint16_t m_windowWidth;
		std::uint16_t m_windowHeight;

	private:
		enum class ControlSignal { HeadOrientationChanged, KeyPressed, WindowExposed, WindowRefreshed, WindowSizeChanged };
		enum class ControlState { Initializing, Rendering, Terminating };

	private:
		void control(ControlSignal signal);

	private:
		ControlState m_state;
	};
}
