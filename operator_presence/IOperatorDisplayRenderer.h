#pragma once

#include "IOperatorEyeRenderer.h"

namespace operator_view
{
	class IOperatorRendererObserver;
}

namespace operator_view
{
	/// \brief An interface for the operator's display rendering
	///
	/// The interface inherits IOperatorRenderer interface so that the classes implementing
	/// this interface must realize the rendering contract.
	/// The main objective of the classes that implement this interface is to provide
	/// the windowing subsystem and a context for 3-D low level API sush as OpenGL or Direct3D.
	///
	/// The interface provides the means to communicate with a mediator by defining the Observer pattern.
	///
	class IOperatorDisplayRenderer : public IOperatorEyeRenderer
	{
	public:
		virtual void registerObserver(std::shared_ptr<IOperatorRendererObserver> observer) = 0;

	private:
		virtual void notifyKeyPressed(Qt::Key key) = 0;
		virtual void notifySizeChanged(std::uint16_t newWidth, std::uint16_t newHeight) = 0;
	};
}
