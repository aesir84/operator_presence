#pragma once

namespace operator_model
{
	class IOperatorHeadOrientation;
	class IOperatorVision;
}

namespace operator_model
{
	class IOperatorModel
	{
	public:
		virtual ~IOperatorModel() { }

	public:
		virtual std::shared_ptr<IOperatorVision> getOperatorVision() = 0;
		virtual std::shared_ptr<IOperatorHeadOrientation> getOperatorHeadOrientation() = 0;
	};
}
