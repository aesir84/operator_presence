#pragma once

namespace operator_view
{
	/// \brief An interface for rendering the operator's entire view
	///
	/// This interface is an abstraction layer for the client - IOperatorView.
	///
	/// More than that, this interface can play a role of a strategy, which
	/// defines the way of rendering the operator's view, e.g. there can be
	/// different strategies to render the view into the operator's HMDs, or
	/// even a strategy to render the view without considering any HMDs,
	/// i.e. rendering simply to the screen.
	///
	/// On the other hand, this interface can be viewed as an adapter between
	/// the IOperatorView and IOperatorRenderer interfaces.
	///
	class IOperatorViewRenderer
	{
	public:
		virtual ~IOperatorViewRenderer() { }

	public:
		virtual void initialize() = 0;
		virtual void render() = 0;
	};
}
