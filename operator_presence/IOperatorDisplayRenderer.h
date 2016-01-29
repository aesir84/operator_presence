#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	class IOperatorDisplayObserver;
}

namespace operator_view
{
	class IOperatorDisplayRenderer : public IOperatorRenderer
	{
	public:
		virtual void registerObserver(std::shared_ptr<IOperatorDisplayObserver> observer) = 0;

	private:
		virtual void notifyKeyPressed(Qt::Key key) = 0;
	};
}
