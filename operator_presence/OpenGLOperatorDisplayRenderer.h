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
			virtual void initialize() override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			void render();

		private:
			QOpenGLContext m_context;

		private:
			virtual void registerObserver(std::shared_ptr<IOperatorDisplayObserver> observer) override;

		private:
			virtual void notifyKeyPressed(Qt::Key key) override;

		private:
			std::vector<std::weak_ptr<IOperatorDisplayObserver>> m_observers;

		private:
			virtual void keyReleaseEvent(QKeyEvent * keyEvent) override;
		};
	}
}
