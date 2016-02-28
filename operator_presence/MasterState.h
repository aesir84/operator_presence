#pragma once

#include "IOperatorState.h"

namespace operator_model
{
	class OperatorModel;
}

namespace operator_model
{
	class MasterState : public IOperatorState
	{
	public:
		MasterState(OperatorModel & operatorModel);

	private:
		OperatorModel & m_operatorModel;

	private:
		virtual void turnBody(double yaw) override;
		virtual void turnHead(double yaw, double pitch, double roll) override;

	private:
		virtual void switchVision(/* to what */) override;
	};
}
