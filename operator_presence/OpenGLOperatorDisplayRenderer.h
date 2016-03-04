#pragma once

#include "IOperatorDisplayRenderer.h"

namespace operator_view
{
	class IOperatorViewMediator;
}

namespace operator_view
{
	namespace opengl
	{
		class OperatorDisplayRenderer : public QWindow, public IOperatorDisplayRenderer
		{
			friend class OperatorRendererFactory;

		private:
			OperatorDisplayRenderer(std::shared_ptr<IOperatorViewMediator> operatorViewMediator);

		public:
			~OperatorDisplayRenderer();

		private:
			std::shared_ptr<IOperatorViewMediator> m_operatorViewMediator;

		private:
			virtual void initialize(std::uint16_t eyeResolutionWidth, std::uint16_t eyeResolutionHeight) override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			void render();
			void setOperatorDisplaySize(std::uint16_t eyeResolutionWidth, std::uint16_t eyeResolutionHeight);

		private:
			QOpenGLContext m_context;

		private:
			virtual void keyReleaseEvent(QKeyEvent * keyEvent) override;
			virtual void resizeEvent(QResizeEvent * resizeEvent) override;
		};
	}
}
