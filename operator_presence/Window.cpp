#include "stdafx.h"

#include "Window.h"

#include "IWindowObserver.h"

namespace model
{
	Window::Window()
	{ }

	void Window::updateSize(QSize const & size)
	{
		m_size = size;

		notifySizeUpdate(m_size);
	}

	void Window::registerObserver(std::shared_ptr<IWindowObserver> observer)
	{
		m_observers.push_back(observer);
	}

	void Window::notifySizeUpdate(QSize const & size)
	{
		for (auto & observer : m_observers)
		{
			auto existingObserver = observer.lock();

			if (existingObserver)
			{
				existingObserver->updateSize(size);
			}
		}
	}
}
