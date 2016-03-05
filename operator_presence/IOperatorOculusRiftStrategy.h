#pragma once

#include "IOperatorViewStrategy.h"

namespace operator_view
{
	class IOperatorViewObserver;
}

namespace operator_view
{
	/// \brief An interface for rendering the operator's view using Oculus Rift strategy
	///
	/// The reason to provide this layer of abstraction is that Oculus Rift
	/// can be configured to use either OpenGL or Direct3D for rendering.
	///
	class IOperatorOculusRiftStrategy : public IOperatorViewStrategy
	{
	public:
		virtual void registerObserver(std::shared_ptr<IOperatorViewObserver> observer) = 0;

	private:
		virtual void notifyHeadsetOrientationChanged(double yaw, double pitch, double roll) = 0;
	};
}
