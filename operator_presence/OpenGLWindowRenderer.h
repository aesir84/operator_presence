#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorRenderer : public IOperatorRenderer, public QWindow
		{
			friend class RendererFactory;

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
		};
	}
}
