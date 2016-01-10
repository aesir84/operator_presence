#include "stdafx.h"

#include "OperatorVision.h"

OperatorVision::OperatorVision()
{ }

void OperatorVision::updateLeftEyeImage(EyeImage eyeImage)
{
	m_leftEyeImage = eyeImage;

	Q_EMIT leftEyeImageUpdated(m_leftEyeImage);
}

void OperatorVision::updateRightEyeImage(EyeImage eyeImage)
{
	m_rightEyeImage = eyeImage;

	Q_EMIT rightEyeImageUpdated(m_rightEyeImage);
}
