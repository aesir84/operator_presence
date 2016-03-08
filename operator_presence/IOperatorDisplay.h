#pragma once

namespace operator_controller
{
	/// \brief An interface for the operator's display component of the operator's view
	///
	/// This interface is a link for the controller
	/// to mediate messages with this particular component.
	///
	class IOperatorDisplay
	{
	public:
		virtual ~IOperatorDisplay() { }

	public:
		virtual void refresh() = 0;
	};
}
