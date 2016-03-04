#include "stdafx.h"

#include "OpenGLOperatorDisplayRenderer.h"

#include "IOperatorViewRendererObserver.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorDisplayRenderer::OperatorDisplayRenderer()
		{ }

		void OperatorDisplayRenderer::initialize(std::uint16_t width, std::uint16_t height)
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
			
			setOperatorDisplaySize(width, height);
			setVisible(true);
		}

		void OperatorDisplayRenderer::renderLeftEye()
		{
			render();
		}

		void OperatorDisplayRenderer::renderRightEye()
		{
			render();
		}

		void OperatorDisplayRenderer::render()
		{
			m_context.makeCurrent(this);
		}

		void OperatorDisplayRenderer::setOperatorDisplaySize(std::uint16_t width, std::uint16_t height)
		{
			std::uint16_t operatorDisplayWidth = width;
			std::uint16_t operatorDisplayHeight = height;

			// There can be different screen sizes, e.g. big, small, etc...
			// In order to fit the operator display on a screen nicely
			// we should check and decrease the operator display size as necessary.
			//
			std::uint16_t const screenWidth = static_cast<std::uint16_t>(screen()->size().width());
			std::uint16_t const screenHeight = static_cast<std::uint16_t>(screen()->size().height());

			while (operatorDisplayWidth >= screenWidth || operatorDisplayHeight >= screenHeight)
			{
				operatorDisplayWidth /= 2;
				operatorDisplayHeight /= 2;
			}

			setWidth(operatorDisplayWidth);
			setHeight(operatorDisplayHeight);
		}

		void OperatorDisplayRenderer::registerObserver(std::shared_ptr<IOperatorViewRendererObserver> observer)
		{
			m_observers.push_back(observer);
		}

		void OperatorDisplayRenderer::notifyKeyPressed(Qt::Key key)
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

		void OperatorDisplayRenderer::notifySizeChanged(std::uint16_t newWidth, std::uint16_t newHeight)
		{
			for (auto & observer : m_observers)
			{
				auto existingObserver = observer.lock();

				if (existingObserver)
				{
					existingObserver->updateSizeChanged(newWidth, newHeight);
				}
			}
		}

		void OperatorDisplayRenderer::keyReleaseEvent(QKeyEvent * keyEvent)
		{
			notifyKeyPressed(static_cast<Qt::Key>(keyEvent->key()));
		}

		void OperatorDisplayRenderer::resizeEvent(QResizeEvent * resizeEvent)
		{
			// In order to trigger the resizing two requirements must be met:
			//
			// 1. the window must be exposed
			// 2. OpenGL context must be already initialized
			//
			// The first requirement is needed, because the resize event
			// comes even when the window is being closed, and it seems rather strange
			// to apply any resizing logic when the window is about to be destroyed.
			// The second requirement is imposed by the fact, that
			// the observers may wait for this event to perform some OpenGL manipulations.
			// It is therefore crucial to make sure that these observers can successfully
			// call OpenGL API, i.e. the context must be created and valid.
			//
			if (isExposed() && m_context.isValid())
			{
				notifySizeChanged(resizeEvent->size().width(), resizeEvent->size().height());
			}
		}
	}
}
