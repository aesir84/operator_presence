#pragma once

#include "IOperatorModel.h"

namespace operator_model
{
	class IMediator;
	class IVision;
}

namespace operator_model
{
	class OperatorModel : public IOperatorModel
	{
	public:
		OperatorModel(std::shared_ptr<IMediator> mediator);

	private:
		virtual void turnHead(double yaw, double pitch, double roll) override;

	private:
		virtual void switchVision(std::uint32_t visionId) override;

	private:
		std::unique_ptr<IVision> m_vision;
	};
}
