#include "stdafx.h"

#include "OpenGLWindowRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		WindowRenderer::WindowRenderer()
		{ }

		void WindowRenderer::initialize()
		{
			// The window's surface type must be set to QSurface::OpenGLSurface
			// to indicate that the window is to be used for OpenGL rendering.
			//
			setSurfaceType(QWindow::OpenGLSurface);

			// Set the required OpenGL surface format, i.e.
			// depth buffer size, OpenGL version, etc.
			//
			QSurfaceFormat format;

			format.setDepthBufferSize(24);
			format.setVersion(3, 3);
			setFormat(format);

			// Set the format of the context.
			// The surface format should be the same as the one set for the window.
			//
			m_context.setFormat(requestedFormat());

			if (!m_context.create())
			{
				Q_ASSERT(false);
			}

		}

		void WindowRenderer::renderLeftEye()
		{
			render();
		}

		void WindowRenderer::renderRightEye()
		{
			render();
		}

		void WindowRenderer::render()
		{
			if (!m_context.makeCurrent(this))
			{
				Q_ASSERT(false);
			}

		}
	}
}
