#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	class IOperatorViewObserver;
}

namespace operator_view
{
	class IOperatorDisplayRenderer : public IOperatorRenderer
	{
	public:
		virtual void registerObserver(std::shared_ptr<IOperatorViewObserver> observer) = 0;

	private:
		virtual void notifyKeyPressed(Qt::Key key) = 0;
		virtual void notifySizeChanged(std::uint16_t newWidth, std::uint16_t newHeight) = 0;
	};
}
