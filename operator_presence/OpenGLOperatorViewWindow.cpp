#include "stdafx.h"

#include "OpenGLOperatorViewWindow.h"

#include "IOperatorViewMediator.h"

namespace operator_view
{
	namespace opengl
	{
		Window::~Window()
		{
			if (m_window != nullptr)
			{
				assert(m_context != nullptr);

				SDL_GL_DeleteContext(m_context);
				SDL_DestroyWindow(m_window);
				SDL_Quit();
			}
		}

		Window::Window(std::shared_ptr<IMediator> mediator)
			: m_mediator(mediator)
			, m_window(nullptr)
			, m_context(nullptr)
		{
			m_mediator->registerWindow(this);
		}

		void Window::initialize(std::uint16_t & width, std::uint16_t & height)
		{
			bool const sdlInitialized = SDL_Init(SDL_INIT_VIDEO) != 0;
			if (!sdlInitialized)
			{
				// TODO : handle the error, throw | to log use SDL_GetError()
			}
			auto sdlInitializationReverse = helpers::guard_scope([] { SDL_Quit(); });

			auto windowWidth = width;
			auto windowHeight = height;

			adaptWindowSizeToScreenSize(windowWidth, windowHeight);

			auto x = SDL_WINDOWPOS_CENTERED;
			auto y = SDL_WINDOWPOS_CENTERED;
			auto flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;

			SDL_Window * window = SDL_CreateWindow("operator presence", x, y, windowWidth, windowHeight, flags);
			if (window == nullptr)
			{
				// TODO : handle the error, throw | to log use SDL_GetError()
			}
			auto windowCreationReverse = helpers::guard_scope([window] { SDL_DestroyWindow(window); });

			SDL_GLContext context = SDL_GL_CreateContext(window);
			if (context == nullptr)
			{
				// TODO : handle the error, throw | to log use SDL_GetError()
			}
			auto contextCreationReverse = helpers::guard_scope([context] { SDL_GL_DeleteContext(context); });

			auto const glewInitializationResult = glewInit();
			if (glewInitializationResult != GLEW_OK)
			{
				// TODO : handle the error, throw | to log use glewGetErrorString(glewInitializationResult)
			}

			// The swap interval setting controls when the front and back frame buffers are actually swapped.
			// The term "swap interval" itself refers to the number of v-blanks that must occur before the front and back frame buffers are swapped.
			// A swap interval of 0 specifies that the GPU should not wait for any v-blanks,
			// but rather perform buffer swaps as soon as possible when rendering for a frame is finished.
			//
			bool const vSyncTurnedOff = SDL_GL_SetSwapInterval(0) == 0;
			if (!vSyncTurnedOff)
			{
				// TODO : handle the error, throw | to log use glewGetErrorString(glewInitializationResult)
			}

			contextCreationReverse.dismiss();
			windowCreationReverse.dismiss();
			sdlInitializationReverse.dismiss();

			width = windowWidth;
			height = windowHeight;

			m_context = context;
			m_window = window;
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
			SDL_Event event;

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_KEYUP)
				{
					if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						m_mediator->notifyEscapeKeyPressed();
					}
				}
			}
		}

		void Window::adaptWindowSizeToScreenSize(std::uint16_t & width, std::uint16_t & height)
		{
			auto const displaysCount = SDL_GetNumVideoDisplays();

			if (displaysCount == 0)
			{
				// TODO : handle the error, throw
			}
			
			int const currentDisplayIndex = 0;
			SDL_DisplayMode currentDisplayMode;

			bool const currentDisplayModeRetrieved = SDL_GetCurrentDisplayMode(currentDisplayIndex, &currentDisplayMode) == 0;
			if (!currentDisplayModeRetrieved)
			{
				// TODO : handle the error, throw
			}

			// There can be different display sizes, e.g. big, small, etc...
			// In order to fit the operator window on a display nicely
			// we should check and decrease the operator window size as necessary.
			//
			std::uint16_t const displayWidth = static_cast<std::uint16_t>(currentDisplayMode.w);
			std::uint16_t const displayHeight = static_cast<std::uint16_t>(currentDisplayMode.h);

			while (width >= displayWidth || height >= displayHeight)
			{
				width /= 2;
				height /= 2;
			}
		}
	}
}
