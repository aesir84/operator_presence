#pragma once

namespace operator_model
{
	class IOperatorModel;
}

namespace operator_view
{
	class IFactory;
	class IMediator;
	class IOperatorView;
	class IRenderer;
}

namespace operator_view
{
	/// \brief An operator view builder
	///
	/// The class follows the Builder pattern
	/// and is meant to hide the details of
	/// the rendering classes' construction.
	/// The class must be instantiated through
	/// derived classes, hence the protected
	/// constructor. The only purpose of the
	/// derived classes is to supply a proper
	/// abstract factory objects to this class,
	/// so that appropriate rendering objects -
	/// OpenGL, Direct3D, etc - can be created.
	///
	class Builder
	{
	protected:
		Builder(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<IMediator> mediator, std::unique_ptr<IFactory> factory);

	public:
		/// \brief A destructor
		///
		/// Here it is mandatory to provide a destructor,
		/// which definition must be in the source file (cpp).
		/// Failing to do so will result in a complile-time
		/// error due to the incomplete types used for the
		/// smart pointers present in this class definition.
		/// For example, std::unique_ptr fails to delete its
		/// managed object in case of an incomplete type.
		/// Therefore, it is important to put the definition
		/// of the class's destructor in the source file,
		/// because the source file has the required includes.
		///
		~Builder();

	private:
		std::shared_ptr<operator_model::IOperatorModel> m_model;
		std::shared_ptr<IMediator> m_mediator;

		std::unique_ptr<IFactory> m_factory;

	public:
		/// \brief Additional views
		///

	public:
		enum class DeviceType { Rift };

	public:
		/// \brief The final result output
		///
		/// The method returns a pointer to the interface IOperatorView which is an
		/// abstraction meant to be used by other system parts like the operator controller.
		///
		std::shared_ptr<IOperatorView> build(DeviceType deviceType);

	private:
		std::shared_ptr<IRenderer> m_renderer;
	};
}
