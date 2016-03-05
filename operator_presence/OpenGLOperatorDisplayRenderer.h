#pragma once

#include "IOperatorDisplayRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorDisplayRenderer : public QWindow, public IOperatorDisplayRenderer
		{
			friend class OperatorViewFactory;

		private:
			OperatorDisplayRenderer();

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
			virtual void registerObserver(std::shared_ptr<IOperatorViewObserver> observer) override;

		private:
			std::vector<std::weak_ptr<IOperatorViewObserver>> m_observers;

		private:
			virtual void notifyKeyPressed(Qt::Key key) override;
			virtual void notifyWindowExposed(WId windowId) override;
			virtual void notifyWindowSizeChanged(std::uint16_t width, std::uint16_t height) override;

		private:
			virtual void exposeEvent(QExposeEvent * exposeEvent) override;
			virtual void keyReleaseEvent(QKeyEvent * keyEvent) override;
			virtual void resizeEvent(QResizeEvent * resizeEvent) override;
		};
	}
}
