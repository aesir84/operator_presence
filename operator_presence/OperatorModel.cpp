#include "stdafx.h"

#include "OperatorModel.h"

#include "IOperatorHeadOrientation.h"
#include "IOperatorState.h"
#include "IOperatorVision.h"

#include "MasterState.h"

namespace operator_model
{
	OperatorModel::OperatorModel()
		: m_masterState(std::make_shared<MasterState>(*this))
	{ }

	void OperatorModel::turnBody(double yaw)
	{
		m_state->turnBody(yaw);
	}

	void OperatorModel::turnHead(double yaw, double pitch, double roll)
	{
		m_state->turnHead(yaw, pitch, roll);
	}

	void OperatorModel::switchVision()
	{
		m_state->switchVision();
	}

	void OperatorModel::registerObserver(std::shared_ptr<IOperatorHeadOrientationObserver> observer)
	{
		m_operatorHeadOrientation->registerObserver(observer);
	}

	void OperatorModel::registerObserver(std::shared_ptr<IOperatorVisionObserver> observer)
	{
		m_operatorVision->registerObserver(observer);
	}

	std::shared_ptr<IOperatorHeadOrientation> OperatorModel::getOperatorHeadOrientation() const
	{
		return m_operatorHeadOrientation;
	}

	std::shared_ptr<IOperatorVision> OperatorModel::getOperatorVision() const
	{
		return m_operatorVision;
	}

	std::shared_ptr<IOperatorState> OperatorModel::getState() const
	{
		return m_state;
	}

	void OperatorModel::setState(std::shared_ptr<IOperatorState> state)
	{
		m_state = state;
	}
}
