#pragma once

#include "IOperatorModel.h"

namespace operator_model
{
	class IOperatorHeadOrientation;
	class IOperatorState;
	class IOperatorVision;
}

namespace operator_model
{
	/// \brief An implementation of IOperatorModel interface
	///
	/// This implementation has can be two divided into two parts:
	///
	/// 1. implementation of IOperatorModel interface
	///    The methods implementing the interface are made private,
	///    because the model must be visible to the client only through
	///    the interface, i.e. polymorphically.
	///
	/// 2. an interface for the operator states
	///    The methods that put together this interface are public,
	///    because the states need to access them.
	///    Due to the fact that the main client of the model,
	///    i.e. the controller, must access the model only through
	///    IOperatorModel interface, this client and also any other one
	///    is oblivious to the additional interface made specifically
	///    for the states of the model.
	///
	/// As was stated earlier the model uses the State pattern,
	/// which allows the model to internally change its behavior during run-time.
	///
	class OperatorModel : public IOperatorModel
	{
	public:
		OperatorModel();

	private:
		virtual void turnBody(double yaw) override;
		virtual void turnHead(double yaw, double pitch, double roll) override;

	private:
		virtual void switchVision(/* to what */) override;

	private:
		virtual void registerObserver(std::shared_ptr<IOperatorHeadOrientationObserver> observer) override;
		virtual void registerObserver(std::shared_ptr<IOperatorVisionObserver> observer) override;

	public:
		std::shared_ptr<IOperatorHeadOrientation> getOperatorHeadOrientation() const;
		std::shared_ptr<IOperatorVision> getOperatorVision() const;

	private:
		std::shared_ptr<IOperatorHeadOrientation> m_operatorHeadOrientation;
		std::shared_ptr<IOperatorVision> m_operatorVision;

	public:
		std::shared_ptr<IOperatorState> getState() const;
		void setState(std::shared_ptr<IOperatorState> state);

	private:
		/// \brief The current state of the model
		///
		/// This state represents the current behaviour of the model.
		///
		std::shared_ptr<IOperatorState> m_state;

	private:
		/// \brief A list of all available states of the model
		///
		/// The states represent different behaviours of the model.
		///
		std::shared_ptr<IOperatorState> m_masterState;
	};
}
