#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	class IOperatorRendererObserver;
}

namespace operator_view
{
	/// \brief An interface for the operator's display rendering
	///
	/// The main objective of the classes that implement this interface is to provide
	/// the windowing subsystem and a context for 3-D low level API, sush as OpenGL or Direct3D.
	/// Therefore, the reason of this interface is to provide an abstration layer between the client and a concrete 3-D API.
	///
	/// The interface also provides the means to communicate with a mediator by defining the Observer pattern.
	///
	class IOperatorDisplayRenderer : public IOperatorRenderer
	{
	public:
		virtual void registerObserver(std::shared_ptr<IOperatorRendererObserver> observer) = 0;

	private:
		virtual void notifyKeyPressed(Qt::Key key) = 0;
		virtual void notifySizeChanged(std::uint16_t newWidth, std::uint16_t newHeight) = 0;
	};
}
