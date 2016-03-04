#pragma once

namespace operator_view
{
	/// \brief An interface for rendering the operator's eye visions
	///
	/// The operator has two eyes, so this interface allows to render the images for both eyes.
	/// The interface also allows for delayed initialization.
	///
	class IOperatorEyeRenderer
	{
	public:
		virtual ~IOperatorEyeRenderer() { }

	public:
		virtual void initialize(std::uint16_t eyeResolutionWidth, std::uint16_t eyeResolutionHeight) = 0;

		virtual void renderLeftEye() = 0;
		virtual void renderRightEye() = 0;
	};
}
