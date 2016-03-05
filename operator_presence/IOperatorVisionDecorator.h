#pragma once

#include "IOperatorViewDecorator.h"
#include "IOperatorVisionObserver.h"

namespace operator_view
{
	/// \brief An interface for the operator's vision renderer
	///
	/// The purpose of this interface is to provide an abstraction
	/// from the concrete 3-D API, namely, this renderer can be either
	/// OpenGL or Direct3D. The interface inherits the decorator
	/// interface. The interface also inherits the interface of the
	/// model observer in order to receive the images for the vision.
	///
	class IOperatorVisionRenderer : public IOperatorViewDecorator, public operator_model::IOperatorVisionObserver
	{
	public:
		IOperatorVisionRenderer(std::shared_ptr<IOperatorViewRenderer> renderer)
			: IOperatorViewDecorator(renderer)
		{ }
	};
}
