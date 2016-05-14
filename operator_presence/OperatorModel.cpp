#include "stdafx.h"

#include "OperatorModel.h"

#include "OperatorModelVision.h"

namespace operator_model
{
	OperatorModel::OperatorModel(std::shared_ptr<IMediator> mediator)
		: m_vision(std::make_unique<Vision>(mediator))
	{ }

	void OperatorModel::turnHead(double yaw, double pitch, double roll)
	{
		/* not yet implemented */
	}

	void OperatorModel::switchVision(std::uint32_t visionId)
	{
		/* not yet implemented */
	}
}
