#pragma once

#include "IOperatorViewDecorator.h"
#include "IOperatorVisionObserver.h"

namespace operator_view
{
	/// \brief An interface for the operator's view vision decorator
	///
	/// The purpose of this interface is to provide an abstraction
	/// from the concrete 3-D API, namely, this decorator can be either
	/// OpenGL or Direct3D. The interface inherits the decorator
	/// interface. The interface also inherits the interface of the
	/// model observer in order to receive the images for the vision.
	///
	class IVision : public IDecorator, public operator_model::IOperatorVisionObserver
	{
	public:
		IVision(std::shared_ptr<IRenderer> decoratedRenderer) : IDecorator(decoratedRenderer) { }
	};
}
