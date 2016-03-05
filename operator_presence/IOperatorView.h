#pragma once

namespace operator_view
{
	class IOperatorViewObserver;
}

namespace operator_view
{
	class IOperatorView
	{
	public:
		virtual ~IOperatorView() { }

	public:
		virtual void initialize() = 0;
		virtual void render() = 0;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorViewObserver> observer) = 0;
	};
}
