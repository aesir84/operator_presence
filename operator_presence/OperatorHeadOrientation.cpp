#include "stdafx.h"

#include "OperatorHeadOrientation.h"

#include "IOperatorHeadOrientationObserver.h"

namespace operator_model
{
	OperatorHeadOrientation::OperatorHeadOrientation()
		: m_yaw(0.0)
		, m_pitch(0.0)
		, m_roll(0.0)
	{ }

	void OperatorHeadOrientation::setHeadOrientation(double yaw, double pitch, double roll)
	{
		m_yaw = yaw;
		m_pitch = pitch;
		m_roll = roll;

		notifyHeadOrientationChanged(m_yaw, m_pitch, m_roll);
	}

	void OperatorHeadOrientation::registerObserver(std::shared_ptr<IOperatorHeadOrientationObserver> observer)
	{
		m_observers.push_back(observer);
	}

	void OperatorHeadOrientation::notifyHeadOrientationChanged(double yaw, double pitch, double roll)
	{
		for (auto & observer : m_observers)
		{
			auto existingObserver = observer.lock();

			if (existingObserver)
			{
				existingObserver->updateHeadOrientation(yaw, roll, pitch);
			}
		}
	}
}
