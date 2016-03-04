#pragma once

#include "IOperatorViewRenderer.h"

namespace operator_view
{
	class IOperatorViewRendererObserver;
}

namespace operator_view
{
	/// \brief An interface for the operator's display rendering
	///
	/// Although this interface inherits the interface IOperatorViewRenderer,
	/// the main objective of the classes that implement this interface is to provide
	/// the windowing subsystem and a context for 3-D low level API, sush as OpenGL or Direct3D.
	/// The interface also provides the means to communicate with a mediator by defining the Observer pattern.
	///
	class IOperatorDisplayRenderer : public IOperatorViewRenderer
	{
	public:
		virtual void registerObserver(std::shared_ptr<IOperatorViewRendererObserver> observer) = 0;

	private:
		virtual void notifyKeyPressed(Qt::Key key) = 0;
		virtual void notifySizeChanged(std::uint16_t newWidth, std::uint16_t newHeight) = 0;
	};
}
