#pragma once

namespace operator_model
{
	class IOperatorModel;
}

namespace operator_view
{
	class IOperatorRenderer;
	class IOperatorRendererFactory;
	class IOperatorView;
	class IOperatorViewObserver;
}

namespace operator_view
{
	/// \brief An operator view builder
	///
	/// The class follows the Builder pattern and
	/// is meant to hide the details of the rendering classes' construction.
	///
	/// The class must be instantiated through derived classes,
	/// hence the protected constructor.
	/// The only purpose of the derived classes is to supply a proper abstract factory object
	/// to this class, so that appropriate rendering objects - OpenGL, Direct3D, etc - can be created.
	///
	class OperatorViewBuilder
	{
	protected:
		OperatorViewBuilder(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<IOperatorViewObserver> observer, std::unique_ptr<IOperatorRendererFactory> factory);

	private:
		std::shared_ptr<operator_model::IOperatorModel> m_model;
		std::shared_ptr<IOperatorViewObserver> m_observer;

		std::unique_ptr<IOperatorRendererFactory> m_factory;

	public:
		/// \brief Additional views to display
		///
		void displayHUD();

	public:
		/// \brief The final result output
		///
		/// The main purpose of this method is to take what has already been built and
		/// add the final layer of an HMD renderer. This guarantees that the HMD layer
		/// is always there and is always on the top - exactly like it should be in
		/// order to properly control the flow of rendering.
		///
		/// The method returns a pointer to the interface IOperatorView which is an
		/// abstraction meant to be used by other system parts like the operator controller.
		///
		std::shared_ptr<IOperatorView> build();

	private:
		std::shared_ptr<IOperatorRenderer> m_renderer;
	};
}
