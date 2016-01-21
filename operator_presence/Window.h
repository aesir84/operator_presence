#pragma once

#include "IObservableWindow.h"

namespace model
{
	class Window : public IObservableWindow
	{
	public:
		Window();

	public:
		void updateSize(QSize const & size);

	private:
		QSize m_size;

	public:
		virtual void registerObserver(std::shared_ptr<IWindowObserver> observer) override;

	private:
		virtual void notifySizeUpdate(QSize const & size) override;

	private:
		std::vector<std::weak_ptr<IWindowObserver>> m_observers;
	};
}
