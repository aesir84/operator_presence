#pragma once

#include "IOperatorViewRenderer.h"

namespace operator_view
{
	class IOperatorViewObserver;
}

namespace operator_view
{
	/// \brief An interface for the operator's display rendering
	///
	/// The main objective of the classes that implement this interface is to
	/// provide the windowing subsystem and a context for 3-D low level API,
	/// sush as OpenGL or Direct3D. Therefore, the reason of this interface is
	/// to provide an abstration layer between the client and a concrete 3-D API.
	/// Additionally, the interface specifies the Observer pattern.
	///
	class IOperatorDisplayRenderer : public IOperatorViewRenderer
	{
	public:
		virtual void registerObserver(std::shared_ptr<IOperatorViewObserver> observer) = 0;

	private:
		virtual void notifyKeyPressed(Qt::Key key) = 0;
		virtual void notifyWindowExposed(WId windowId) = 0;
		virtual void notifyWindowSizeChanged(std::uint16_t width, std::uint16_t height) = 0;
	};
}
