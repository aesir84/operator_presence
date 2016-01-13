#include "stdafx.h"

#include "Window.h"

namespace model
{
	Window::Window()
	{ }

	void Window::registerObserver(std::shared_ptr<IWindowObserver> observer)
	{
		m_observers.push_back(observer);
	}
}
