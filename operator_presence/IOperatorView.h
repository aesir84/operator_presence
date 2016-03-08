#pragma once

namespace operator_view
{
	/// \brief An interface for the operator's view
	///
	/// The operator's view as a 'dumb device' in a sense
	/// that it does not contain any UI business logic.
	/// The main purpose of the view is to render certain
	/// things in one way or another. All the decisions related
	/// to the UI business logic are taken by the operator's controller.
	/// Thus, again, the view only renders, takes requests from the controller
	/// and notifies the controller when it detects some certain user actions or events.
	///
	class IOperatorView
	{
	public:
		virtual ~IOperatorView() { }

	public:
		virtual void initialize() = 0;
		virtual void render() = 0;
	};
}
