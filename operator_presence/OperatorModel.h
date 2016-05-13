#pragma once

#include "IOperatorModel.h"

namespace operator_model
{
	class IOperatorHeadOrientation;
	class IOperatorVision;
}

namespace operator_model
{
	/// \brief An implementation of IOperatorModel interface
	///
	class OperatorModel : public IOperatorModel
	{
	public:
		OperatorModel();

	private:
		virtual void turnBody(double yaw) override;
		virtual void turnHead(double yaw, double pitch, double roll) override;

	private:
		virtual void switchVision(std::uint32_t visionId) override;

	private:
		virtual bool getEyeImages(EyeImage & leftEyeImage, EyeImage & rightEyeImage) override;

	private:
		std::shared_ptr<IOperatorHeadOrientation> m_operatorHeadOrientation;
		std::shared_ptr<IOperatorVision> m_operatorVision;
	};
}
