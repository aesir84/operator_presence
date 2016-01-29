#pragma once

namespace operator_view
{
	class IOperatorDisplayObserver
	{
	public:
		virtual ~IOperatorDisplayObserver() { }

	public:
		virtual void updateKeyPressed(Qt::Key key) = 0;
	};
}
