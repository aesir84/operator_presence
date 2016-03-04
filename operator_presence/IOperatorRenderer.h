#pragma once

namespace operator_view
{
	/// \brief An interface for rendering the operator
	///
	/// This interface is intended to be inherited by more concrete operator renderers.
	/// Since the operator has two eyes, this interface allows rendering to each eye separately.
	/// The interface also allows delayed initialization.
	///
	class IOperatorRenderer
	{
	public:
		virtual ~IOperatorRenderer() { }

	public:
		virtual void initialize(std::uint16_t eyeResolutionWidth, std::uint16_t eyeResolutionHeight) = 0;

		virtual void renderLeftEye() = 0;
		virtual void renderRightEye() = 0;
	};
}
