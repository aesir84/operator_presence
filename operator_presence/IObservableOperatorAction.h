#pragma once

namespace operator_view
{
	class IOperatorActionObserver;
}

namespace operator_view
{
	class IObservableOperatorAction
	{
	public:
		virtual ~IObservableOperatorAction() { }

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorActionObserver> observer) = 0;

	private:
		virtual void notifyKeyPressed(Qt::Key key) = 0;
	};
}
