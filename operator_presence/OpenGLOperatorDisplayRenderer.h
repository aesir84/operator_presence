#pragma once

#include "IOperatorDisplay.h"
#include "IOperatorDisplayRenderer.h"

namespace operator_controller
{
	class IOperatorController;
}

namespace operator_view
{
	namespace opengl
	{
		class OperatorDisplayRenderer : public QWindow, public IOperatorDisplayRenderer, public operator_controller::IOperatorDisplay
		{
			friend class OperatorViewFactory;

		private:
			OperatorDisplayRenderer(std::shared_ptr<operator_controller::IOperatorController> controller);

		private:
			std::shared_ptr<operator_controller::IOperatorController> m_controller;

		private:
			virtual void initialize(std::uint16_t width, std::uint16_t height) override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			void render();
			void setOperatorDisplaySize(std::uint16_t width, std::uint16_t height);

		private:
			QOpenGLContext m_context;

		private:
			virtual void exposeEvent(QExposeEvent * exposeEvent) override;
			virtual void keyReleaseEvent(QKeyEvent * keyEvent) override;
			virtual void resizeEvent(QResizeEvent * resizeEvent) override;
		};
	}
}
