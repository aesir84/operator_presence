#include "stdafx.h"

#include "IOperator.h"

namespace model
{
	Operator::Operator()
	{ }

	void Operator::updateLeftEyeImage(EyeImage eyeImage)
	{
		m_leftEyeImage = eyeImage;

		Q_EMIT leftEyeImageUpdated(m_leftEyeImage);
	}

	void Operator::updateRightEyeImage(EyeImage eyeImage)
	{
		m_rightEyeImage = eyeImage;

		Q_EMIT rightEyeImageUpdated(m_rightEyeImage);
	}
}
