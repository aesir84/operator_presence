#pragma once

#include "IOperatorDisplayRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorDisplayRenderer : public QWindow, public IOperatorDisplayRenderer
		{
			friend class OperatorRendererFactory;

		private:
			OperatorDisplayRenderer();

		private:
			virtual void initialize(std::uint16_t eyeResolutionWidth = 0, std::uint16_t eyeResolutionHeight = 0) override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			void render();
			void setOperatorDisplaySize(std::uint16_t eyeResolutionWidth, std::uint16_t eyeResolutionHeight);

		private:
			QOpenGLContext m_context;

		private:
			virtual void registerObserver(std::shared_ptr<IOperatorDisplayObserver> observer) override;

		private:
			virtual void notifyKeyPressed(Qt::Key key) override;
			virtual void notifySizeChanged(std::uint16_t newWidth, std::uint16_t newHeight) override;

		private:
			std::vector<std::weak_ptr<IOperatorDisplayObserver>> m_observers;

		private:
			virtual void keyReleaseEvent(QKeyEvent * keyEvent) override;
			virtual void resizeEvent(QResizeEvent * resizeEvent) override;
		};
	}
}
