#pragma once

#include "OperatorEyeImageType.h"

namespace operator_model
{
	namespace utils
	{
		class IImageInputStream;
	}
}

namespace operator_model
{
	/// \brief An interface to represent the vision of the operator
	///
	/// The vision of the operator is represented by the eye images, i.e. the left eye image and the right one.
	/// The interface allows setting dataflow strategies, like an update strategy that governs the inflow of new images into the vision.
	///
	class IVision
	{
	public:
		virtual ~IVision() { }

	public:
		virtual void setUpdateStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream) = 0;
	};
}
