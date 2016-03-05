#pragma once

#include "IOperatorViewDecorator.h"
#include "IOperatorVisionObserver.h"

namespace operator_view
{
	/// \brief An interface for the operator's vision decorator
	///
	/// The purpose of this interface is to provide an abstraction
	/// from the concrete 3-D API, namely, this decorator can be either
	/// OpenGL or Direct3D. The interface inherits the decorator
	/// interface. The interface also inherits the interface of the
	/// model observer in order to receive the images for the vision.
	///
	class IOperatorVisionDecorator : public IOperatorViewDecorator, public operator_model::IOperatorVisionObserver
	{
	public:
		IOperatorVisionDecorator(std::shared_ptr<IOperatorViewRenderer> decoratedRenderer)
			: IOperatorViewDecorator(decoratedRenderer)
		{ }
	};
}
