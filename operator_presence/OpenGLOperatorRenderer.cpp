#include "stdafx.h"

#include "OpenGLOperatorRenderer.h"

#include "IOperatorActionObserver.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorRenderer::OperatorRenderer()
		{ }

		void OperatorRenderer::initialize()
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

		void OperatorRenderer::renderLeftEye()
		{
			render();
		}

		void OperatorRenderer::renderRightEye()
		{
			render();
		}

		void OperatorRenderer::render()
		{
			m_context.makeCurrent(this);
		}

		void OperatorRenderer::registerObserver(std::shared_ptr<IOperatorActionObserver> observer)
		{
			m_observers.push_back(observer);
		}

		void OperatorRenderer::notifyKeyPressed(Qt::Key key)
		{
			for (auto & observer : m_observers)
			{
				auto existingObserver = observer.lock();

				if (existingObserver)
				{
					existingObserver->updateKeyPressed(key);
				}
			}
		}

		void OperatorRenderer::keyReleaseEvent(QKeyEvent * keyEvent)
		{
			notifyKeyPressed(keyEvent->key);
		}
	}
}
