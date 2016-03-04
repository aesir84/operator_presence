#pragma once

namespace operator_view
{
	/// \brief An interface for rendering the operator's view
	///
	/// The operator has two eyes, so this interface allows to render the view to both eyes.
	/// This means that the view will be divided in half when being displayed,
	/// and each eye will get half of this view
	/// The interface also allows for delayed initialization.
	///
	class IOperatorViewRenderer
	{
	public:
		virtual ~IOperatorViewRenderer() { }

	public:
		/// \brief An initialization of the view
		///
		/// This method allows to perform delayed initialization of the view.
		/// The method accepts two parameters:
		/// 1. the width of the view
		/// 2. the height of the view
		/// Consequently, in order to accomodate the view for both eyes,
		/// the eye images should have the width of the view divided in half.
		///
		virtual void initialize(std::uint16_t width, std::uint16_t height) = 0;

		/// \brief Methods to render each eye separately
		///
		/// The methods should render their portion of the view,
		/// the portion that was allocated for each of the eyes.
		///
		virtual void renderLeftEye() = 0;
		virtual void renderRightEye() = 0;
	};
}
