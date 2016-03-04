#pragma once

#include "IOperatorViewRenderer.h"

namespace operator_view
{
	class IOperatorRendererObserver;
}

namespace operator_view
{
	/// \brief An interface for Oculus Rift renderer
	///
	/// The reason to provide this layer of abstraction is that Oculus Rift
	/// can be configured for either OpenGL or Direct3D rendering.
	///
	/// The interface also provides the means to communicate with a mediator
	/// by using the Observer pattern.
	///
	class IOperatorOculusRiftRenderer : public IOperatorViewRenderer
	{
	public:
		virtual void registerObserver(std::shared_ptr<IOperatorRendererObserver> observer) = 0;

	public:
		virtual void notifyHeadOrientationChanged(double yaw, double pitch, double roll) = 0;
	};
}
