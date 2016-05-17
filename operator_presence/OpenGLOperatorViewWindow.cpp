#include "stdafx.h"

#include "OpenGLOperatorViewWindow.h"

#include "IOperatorViewMediator.h"

namespace operator_view
{
	namespace opengl
	{
		Window::~Window()
		{ }

		Window::Window(std::shared_ptr<IMediator> mediator)
			: m_mediator(mediator)
		{
			m_mediator->registerWindow(this);
		}

		void Window::initialize(std::uint16_t & width, std::uint16_t & height)
		{
			assert(!m_window.isOpen());

			auto windowWidth = width;
			auto windowHeight = height;
			adaptWindowSizeToScreenSize(windowWidth, windowHeight);

			// Setup the parameters of the required OpenGL context.
			//
			unsigned int const depthBufferBits = 24;
			unsigned int const stencilBufferBits = 8;
			unsigned int const antialiasingLevel = 0;
			unsigned int const contextVersionMajorNumber = 3;
			unsigned int const contextVersionMinorNumber = 3;
			sf::ContextSettings contextSetings(depthBufferBits, stencilBufferBits, antialiasingLevel, contextVersionMajorNumber, contextVersionMinorNumber);

			// By creating a window in SFML the required OpenGL context is created as well.
			//
			m_window.create(sf::VideoMode(windowWidth, windowHeight), "Operator Presence Application", sf::Style::Default, contextSetings);

			if (!m_window.isOpen())
			{
				// TODO: handle
			}

			// The swap interval setting controls when the front and back frame buffers are actually swapped.
			// The term "swap interval" itself refers to the number of v-blanks that must occur before the front and back frame buffers are swapped.
			// A swap interval of 0 specifies that the GPU should not wait for any v-blanks,
			// but rather perform buffer swaps as soon as possible when rendering for a frame is finished.
			//
			m_window.setVerticalSyncEnabled(false);

			// GLEW is initialized only once the required OpenGL context has been created.
			//
			GLenum glewError = glewInit();

			if (glewError != GLEW_OK)
			{
				glewGetErrorString(glewError);
				// TODO: handle
			}

			// When everything is done, propagate back the adjusted window dimensions.
			//
			width = windowWidth;
			height = windowHeight;

			assert(m_window.isOpen());
		}

		void Window::renderLeftEye()
		{
			render();
		}

		void Window::renderRightEye()
		{
			render();
		}

		void Window::render()
		{
			assert(m_window.isOpen());

			sf::Event event;
			while (m_window.pollEvent(event))
			{
				switch (event.type)
				{
					case sf::Event::Closed:
					{
						m_mediator->notifyWindowClosed();
					}
					break;

					case sf::Event::Resized:
					{
						m_mediator->notifyWindowSizeChanged(event.size.width, event.size.height);
					}
					break;
				}
			}
		}

		void Window::adaptWindowSizeToScreenSize(std::uint16_t & width, std::uint16_t & height)
		{
			auto currentVideoMode = sf::VideoMode::getDesktopMode();

			// There can be different display sizes, e.g. big, small, etc...
			// In order to fit the operator window on a display nicely
			// we should check and decrease the operator window size as necessary.
			//
			std::uint16_t const displayWidth = static_cast<std::uint16_t>(currentVideoMode.width);
			std::uint16_t const displayHeight = static_cast<std::uint16_t>(currentVideoMode.height);

			while (width >= displayWidth || height >= displayHeight)
			{
				width /= 2;
				height /= 2;
			}
		}
	}
}
