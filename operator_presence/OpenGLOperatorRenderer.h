#pragma once

#include "IObservableOperatorAction.h"
#include "IOperatorRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorRenderer
			: public QWindow
			, public IOperatorRenderer
			, public IObservableOperatorAction
		{
			friend class OperatorRendererFactory;

		private:
			OperatorRenderer();

		private:
			virtual void initialize() override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			void render();

		private:
			QOpenGLContext m_context;

		public:
			virtual void registerObserver(std::shared_ptr<IOperatorActionObserver> observer) override;

		private:
			virtual void notifyKeyPressed(Qt::Key key) override;

		private:
			std::vector<std::weak_ptr<IOperatorActionObserver>> m_observers;

		private:
			virtual void keyReleaseEvent(QKeyEvent * keyEvent) override;
		};
	}
}
