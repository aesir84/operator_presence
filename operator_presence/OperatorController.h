#pragma once

#include "IOperatorController.h"
#include "IOperatorViewMediator.h"

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
	class OperatorController : public IOperatorController, public operator_view::IMediator, public std::enable_shared_from_this<OperatorController>
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

	public:
		virtual void run() override;

	public:
		virtual void registerDevice(operator_view::IDevice * device) override;
		virtual void registerWindow(operator_view::IWindow * window) override;

	private:
		operator_view::IDevice * m_device;
		operator_view::IWindow * m_window;

	private:
		virtual void notifyEscapeKeyPressed() override;
		virtual void notifyWindowCreated(std::uint32_t windowId) override;

	private:
		enum class Event
		{
			EscapeKeyPressed
		};

	private:
		std::queue<Event> m_events;
	};
}