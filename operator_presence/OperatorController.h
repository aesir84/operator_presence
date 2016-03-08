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
		virtual void updateHeadsetOrientationChanged(double yaw, double pitch, double roll) override;
		virtual void updateKeyPressed(Qt::Key key) override;
		virtual void updateWindowExposed(WId windowId) override;
		virtual void updateWindowRefreshed() override;
		virtual void updateWindowSizeChanged(std::uint16_t width, std::uint16_t height) override;

	private:
		WId m_exposedWindowId;
		Qt::Key m_pressedKey;

	private:
		enum class ControlSignal { KeyPressed, WindowExposed, WindowRefreshed };
		enum class ControlState { Initializing, Rendering, Terminating };

	private:
		void control(ControlSignal signal);

	private:
		ControlState m_state;
	};
}
