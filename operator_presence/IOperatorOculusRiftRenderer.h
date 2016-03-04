#pragma once

#include "IOperatorViewRenderer.h"

namespace operator_view
{
	/// \brief An interface for Oculus Rift renderer
	///
	/// The reason to provide this layer of abstraction is that Oculus Rift
	/// can be configured for either OpenGL or Direct3D rendering.
	///
	class IOperatorOculusRiftRenderer : public IOperatorViewRenderer
	{ }; // currently the interface is empty, but it still is a placeholder for future enhacements
}
