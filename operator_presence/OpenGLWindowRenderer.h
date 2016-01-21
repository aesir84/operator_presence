#pragma once

#include "IRenderer.h"
#include "IWindowObserver.h"

namespace view
{
	namespace opengl
	{
		class WindowRenderer : public IRenderer, public model::IWindowObserver, public QWindow
		{
			friend class RendererFactory;

		private:
			WindowRenderer();

		private:
			virtual void initialize() override;
			virtual void render() override;

		private:
			QOpenGLContext m_context;
		};
	}
}
