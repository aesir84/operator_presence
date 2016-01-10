#include "stdafx.h"

#include "Operator.h"

namespace model
{
	Operator::Operator()
	{ }

	void Operator::updatePosition(QVector3D const & position)
	{
		m_position = position;

		Q_EMIT positionUpdated(m_position);
	}

	void Operator::updateLeftEyeImage(QImage const & eyeImage)
	{
		m_leftEyeImage = eyeImage;

		Q_EMIT leftEyeImageUpdated(m_leftEyeImage);
	}

	void Operator::updateRightEyeImage(QImage const & eyeImage)
	{
		m_rightEyeImage = eyeImage;

		Q_EMIT rightEyeImageUpdated(m_rightEyeImage);
	}
}
