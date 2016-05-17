#pragma once

#include "OperatorEyeImageType.h"

#include "IOperatorController.h"
#include "IOperatorModelMediator.h"
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
	class OperatorController
		: public IOperatorController
		, public operator_model::IMediator
		, public operator_view::IMediator
		, public std::enable_shared_from_this<OperatorController>
	{
	public:
		static std::shared_ptr<IOperatorController> create();

	private:
		OperatorController();

	private:
		void initializeModel();
		void initializeView();

	private:
		std::shared_ptr<operator_model::IOperatorModel> m_model;
		std::shared_ptr<operator_view::IOperatorView> m_view;

	public:
		virtual void run() override;

	private:
		bool m_controllerStopped{ false };

	private:
		virtual void registerVision(operator_model::IVision * vision) override;

	private:
		operator_model::IVision * m_modelVision{ nullptr };

	private:
		virtual void notifyLeftEyeImageUpdated(operator_model::EyeImage leftEyeImage) override;
		virtual void notifyRightEyeImageUpdated(operator_model::EyeImage rightEyeImage) override;

	private:
		std::atomic<bool> m_leftEyeImageUpdated{ false };
		std::atomic<bool> m_rightEyeImageUpdated{ false };

		operator_model::EyeImage m_leftEyeImage;
		operator_model::EyeImage m_rightEyeImage;

		std::mutex m_eyeImagesGuard;

	private:
		void handleModelEvents();

	private:
		virtual void registerDevice(operator_view::IDevice * device) override;
		virtual void registerVision(operator_view::IVision * vision) override;
		virtual void registerWindow(operator_view::IWindow * window) override;

	private:
		operator_view::IDevice * m_viewDevice{ nullptr };
		operator_view::IVision * m_viewVision{ nullptr };
		operator_view::IWindow * m_viewWindow{ nullptr };

	private:
		virtual void notifyDeviceOrientationChanged(double yaw, double pitch, double roll) override;
		virtual void notifyWindowClosed() override;
		virtual void notifyWindowSizeChanged(std::uint16_t width, std::uint16_t height) override;

	private:
		enum class ViewEvent
		{
			WindowClosed,
			WindowSizeChanged,
		};
		std::queue<ViewEvent> m_viewEvents;

	private:
		std::uint16_t m_windowWidth;
		std::uint16_t m_windowHeight;

	private:
		void handleViewEvents();
	};
}
