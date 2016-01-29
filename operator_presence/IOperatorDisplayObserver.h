#pragma once

namespace operator_view
{
	class IOperatorActionObserver
	{
	public:
		virtual ~IOperatorActionObserver() { }

	public:
		virtual void updateKeyPressed(Qt::Key key) = 0;
	};
}
