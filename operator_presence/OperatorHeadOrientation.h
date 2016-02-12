#pragma once

#include "IOperatorHeadOrientation.h"

namespace operator_model
{
	class OperatorHeadOrientation : public IOperatorHeadOrientation
	{
	public:
		OperatorHeadOrientation();

	public:
		virtual void setHeadOrientation(double yaw, double pitch, double roll) override;

	private:
		double m_yaw;
		double m_pitch;
		double m_roll;

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorHeadOrientationObserver> observer) override;

	private:
		std::vector<std::weak_ptr<IOperatorHeadOrientationObserver>> m_observers;

	private:
		virtual void notifyHeadOrientationChanged(double yaw, double pitch, double roll) override;
	};
}
