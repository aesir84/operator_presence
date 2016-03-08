#pragma once

namespace operator_controller
{
	/// \brief An interface for the operator's headset component of the operator's view
	///
	/// This interface is a link for the controller
	/// to mediate messages with this particular component.
	///
	class IOperatorHeadset
	{
	public:
		virtual ~IOperatorHeadset() { }

	public:
		virtual void setWindowId(WId winId) = 0;
	};
}
