#include "stdafx.h"

#include "OpenGLOperatorViewWindow.h"

#include "IOperatorViewMediator.h"

namespace operator_view
{
	namespace opengl
	{
		Window::Window(std::shared_ptr<IMediator> mediator)
			: m_mediator(mediator)
		{
			m_mediator->registerWindow(this);
		}

		void Window::initialize(std::uint16_t width, std::uint16_t height)
		{
			// TODO : implement
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
		}

		void Window::setOperatorDisplaySize(std::uint16_t width, std::uint16_t height)
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

			// TODO : apply the dimensions
		}
	}
}
