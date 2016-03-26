#pragma once

#include "IOperatorViewDevice.h"

namespace operator_view
{
	/// \brief An interface for rendering the operator's view using Oculus Rift device strategy
	///
	/// The reason to provide this layer of abstraction is that Oculus Rift
	/// can be configured to use either OpenGL or Direct3D for rendering.
	///
	class IRift : public IDevice
	{ };
}
