#pragma once

namespace operator_view
{
	/// \brief An interface for rendering the operator's view
	///
	/// Each class implementing this interface shall render its own
	/// specific part of the whole view, e.g. a display, vision, HUD, etc.
	/// Since the operator has two eyes, this interface allows rendering to each eye separately.
	/// The interface also favors delayed initialization.
	///
	class IOperatorViewRenderer
	{
	public:
		virtual ~IOperatorViewRenderer() { }

	public:
		/// \brief A method to perform delayed initialization
		///
		/// This method may be used to perform rendering
		/// specific initialization, which which should be delayed
		/// until some proper conditions for initialization are met.
		/// \param The width of the operator's view
		/// \param The height of the operator's view
		///
		virtual void initialize(std::uint16_t width, std::uint16_t height) = 0;

		virtual void renderLeftEye() = 0;
		virtual void renderRightEye() = 0;
	};
}
