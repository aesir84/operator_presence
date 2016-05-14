#pragma once

#include "IOperatorModelVision.h"

namespace operator_model
{
	class IMediator;
}

namespace operator_model
{
	/// \brief The implementation of the operator's vision
	///
	/// This class realizes the IVision interface.
	/// The responsabilities of this class include:
	///  * managing the dataflow strategies;
	///  * notifying the mediator about state updates.
	///
	class Vision : public IVision
	{
	public:
		explicit Vision(std::shared_ptr<IMediator> mediator);

	private:
		std::shared_ptr<IMediator> m_mediator;

	public:
		virtual void setUpdateStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream) override;

	private:
		class EyeImageUpdater;

		std::unique_ptr<EyeImageUpdater> m_leftEyeImageUpdater;
		std::unique_ptr<EyeImageUpdater> m_rightEyeImageUpdater;

	private:
		void updateLeftEyeImage(EyeImage leftEyeImage);
		void updateRightEyeImage(EyeImage rightEyeImage);
	};
}
