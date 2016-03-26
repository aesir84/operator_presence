#pragma once

namespace operator_controller
{
	/// \brief An interface for the operator's controller
	///
	/// The controller provides a 'game' loop for the application.
	/// Therefore, the tasks of the controller are as follows:
	///    * update/render the view
	///    * handle user input
	///    * update the model
	///    * ...
	///
	/// The controller should not depend on a particular windowing system,
	/// i.e. on some specific library which provides windowing capabilities.
	/// Rather than that, the controller should be abstracted from these details.
	///
	class IOperatorController
	{
	public:
		virtual ~IOperatorController() { }

	public:
		/// \brief The 'game' loop
		///
		/// This method should implement a traditional blocking gaming loop.
		/// The intent is to make things very straightforward and understandable.
		///
		virtual void run() = 0;
	};
}
