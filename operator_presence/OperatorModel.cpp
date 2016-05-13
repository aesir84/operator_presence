#include "stdafx.h"

#include "OperatorModel.h"

#include "IOperatorHeadOrientation.h"
#include "IOperatorVision.h"

namespace operator_model
{
	OperatorModel::OperatorModel()
	{ }

	void OperatorModel::turnBody(double yaw)
	{
		/* not yet implemented */
	}

	void OperatorModel::turnHead(double yaw, double pitch, double roll)
	{
		/* not yet implemented */
	}

	void OperatorModel::switchVision(std::uint32_t visionId)
	{
		/* not yet implemented */
	}

	bool OperatorModel::getEyeImages(EyeImage & leftEyeImage, EyeImage & rightEyeImage)
	{
		/* not yet implemented */
	}
}
