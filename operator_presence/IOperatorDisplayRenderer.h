#pragma once

#include "IOperatorViewRenderer.h"

namespace operator_view
{
	/// \brief An interface for the operator's display rendering
	///
	/// The main objective of the classes that implement this interface is to
	/// provide the windowing subsystem and a context for 3-D low level API,
	/// sush as OpenGL or Direct3D. Therefore, the reason of this interface is
	/// to provide an abstration layer between the client and a concrete 3-D API.
	///
	class IOperatorDisplayRenderer : public IOperatorViewRenderer
	{ };
}
