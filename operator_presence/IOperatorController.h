#pragma once

/// \brief Forward declaration of the components of the operator's view
///
/// These components are represented as their corresponding interfaces,
/// which serve as links between the controller - the mediator - and
/// concrete instances of the components of the operator's view.
///
namespace operator_controller
{
	class IOperatorDisplay;
	class IOperatorHeadset;
}

namespace operator_controller
{
	/// \brief An interface for the operator's controller
	///
	/// The controller serves as a mediator for the operator's view.
	/// Therefore, the main tasks of the controller are:
	/// * take a decision once some event is detected by the view
	/// * act correspondingly to the taken decision
	///
	class IOperatorController
	{
	public:
		virtual ~IOperatorController() { }

	public:
		/// \brief Registration of the components of the operator's view
		///
		/// The controller requires the components to register themselves
		/// in order to be able to act on them once a decision is taken
		///
		virtual void registerOperatorDisplay(IOperatorDisplay * operatorDisplay) = 0;
		virtual void registerOperatorHeadset(IOperatorHeadset * operatorHeadset) = 0;

	public:
		virtual void updateHeadsetOrientationChanged(double yaw, double pitch, double roll) = 0;
		virtual void updateKeyPressed(Qt::Key key) = 0;
		virtual void updateWindowExposed(WId windowId) = 0;
		virtual void updateWindowRefreshed() = 0;
		virtual void updateWindowSizeChanged(std::uint16_t width, std::uint16_t height) = 0;
	};
}
