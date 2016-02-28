#include "stdafx.h"

#include "MasterState.h"

namespace operator_model
{
	MasterState::MasterState(OperatorModel & operatorModel)
		: m_operatorModel(operatorModel)
	{ }

	void MasterState::turnBody(double yaw)
	{
		/* does nothing */
	}

	void MasterState::turnHead(double yaw, double pitch, double roll)
	{
		/* does nothing */
	}

	void MasterState::switchVision(/* to what */)
	{
		/* not yet implemented */
	}
}
