#pragma once

#include "IRenderer.h"

namespace view
{
	namespace opengl
	{
		class WindowRenderer : public IRenderer
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
