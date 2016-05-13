#pragma once

#include "OperatorEyeImageType.h"

namespace operator_model
{
	namespace utils
	{
		class IImageInputStream;
	}
}

namespace operator_model
{
	/// \brief An interface to represent the vision of the operator
	///
	/// The vision of the operator is represented by the eye images, i.e. the left eye image and the right one.
	/// The responsability of the vision is to control the flow of the eye images.
	///
	/// The inflow is provided by the updating strategies. The strategies are allowed to be changed during the runtime.
	///
	/// The outflow is served on-demand, i.e. whenever the client wants to get an update of the vision,
	/// it has to explicitly request this update. This kind of service model is justified by the fact that
	/// the vision is quiried by the gaming loop which runs at some specified points in time. Thus,
	/// it makes more sense to provide an on-demand service rather than the one based on notifications.
	///
	class IOperatorVision
	{
	public:
		virtual ~IOperatorVision() { }

	public:
		virtual void setUpdateStrategy(std::shared_ptr<utils::IImageInputStream> leftEyeStream, std::shared_ptr<utils::IImageInputStream> rightEyeStream) = 0;

	public:
		/// \brief Update retriever method
		///
		/// The method realizes the on-demand behaviour of the vision,
		/// i.e. the client has to explicitly ask for the update in order to get it.
		/// The method returns successfully only if there are updates for both eye images, i.e. for the left and the right.
		///
		/// \param   leftEyeImage is a non-const reference to a left eye image object to be updated
		/// \param   rightEyeImage is a non-const reference to a right eye image object to be updated
		/// \return  true if there is an update for both eye images, false otherwise
		///
		virtual bool getUpdate(EyeImage & leftEyeImage, EyeImage & rightEyeImage) = 0;
	};
}
