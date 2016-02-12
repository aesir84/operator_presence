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
		virtual std::shared_ptr<IOperatorVision> getVision() const = 0;
		virtual std::shared_ptr<IOperatorHeadOrientation> getHeadOrientation() const = 0;
	};
}
