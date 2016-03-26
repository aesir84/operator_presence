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
		/// By providing a separate method for initialization,
		/// the initialization of an object is separated from its creation.
		/// This can be useful if the object needs to perform a delayed initialization,
		/// i.e. to initialize only when certain conditions are met.
		/// \param The width of the operator's view
		/// \param The height of the operator's view
		///
		virtual void initialize(std::uint16_t width, std::uint16_t height) = 0;

		virtual void renderLeftEye() = 0;
		virtual void renderRightEye() = 0;
	};
}
