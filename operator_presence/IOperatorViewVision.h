#pragma once

#include "IOperatorViewDecorator.h"

namespace operator_view
{
	/// \brief An interface for the operator's view vision decorator
	///
	/// The purpose of this interface is to provide an abstraction
	/// from the concrete 3-D API, namely, this decorator can be either
	/// OpenGL or Direct3D. The interface inherits the decorator
	/// interface. The interface also provides methods to update
	/// the images of the vision.
	///
	class IVision : public IDecorator
	{
	public:
		IVision(std::shared_ptr<IRenderer> decoratedRenderer) : IDecorator(decoratedRenderer) { }

	public:
		virtual void updateLeftEyeImage(Image leftEyeImage) = 0;
		virtual void updateRightEyeImage(Image rightEyeImage) = 0;
	};
}
