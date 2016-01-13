#pragma once

namespace model
{
	class IWindowObserver;
}

namespace model
{
	class IObservableWindow
	{
	public:
		virtual ~IObservableWindow() { }

	public:
		virtual void registerObserver(std::shared_ptr<IWindowObserver> observer) = 0;

	private:
	};
}
