#pragma once

#include "IObservableWindow.h"

namespace model
{
	class Window : public IObservableWindow
	{
	public:
		Window();

	public:
		virtual void registerObserver(std::shared_ptr<IWindowObserver> observer) override;

	private:
		std::vector<std::weak_ptr<IWindowObserver>> m_observers;
	};
}
