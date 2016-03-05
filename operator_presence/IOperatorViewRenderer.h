#pragma once

namespace operator_view
{
	/// \brief An interface for rendering specific parts of the operator
	///
	/// If IOperatorViewRenderer serves as an algorithm to conduct the rendering of the entire operator's view,
	/// then IOperatorRenderer is meant to render concrete parts of the whole view, e.g. a display, vision, HUD, etc.
	/// Since the operator has two eyes, this interface allows rendering to each eye separately.
	/// The interface also favors delayed initialization.
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
