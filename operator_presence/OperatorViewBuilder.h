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
	class IOperatorViewRenderer;
	class IOperatorViewRendererFactory;
	class OperatorView;
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
	/// The only purpose of the derived classes is to supply a proper abstract factory objects
	/// to this class, so that appropriate rendering objects - OpenGL, Direct3D, etc - can be created.
	///
	class OperatorViewBuilder
	{
	protected:
		OperatorViewBuilder
			(
				std::shared_ptr<operator_model::IOperatorModel> operatorModel,
				std::unique_ptr<IOperatorViewRendererFactory> operatorViewRendererFactory,
				std::unique_ptr<IOperatorRendererFactory> operatorRendererFactory
			);

	private:
		std::shared_ptr<operator_model::IOperatorModel> m_operatorModel;

		std::unique_ptr<IOperatorViewRendererFactory> m_operatorViewRendererFactory;
		std::unique_ptr<IOperatorRendererFactory> m_operatorRendererFactory;

	public:
		/// \brief Additional views to display
		///
		void displayHUD();

	public:
		/// \brief The final result output
		///
		/// The method returns a pointer to the interface IOperatorView which is an
		/// abstraction meant to be used by other system parts like the operator controller.
		///
		std::shared_ptr<IOperatorView> build();

	private:
		std::shared_ptr<IOperatorRenderer> m_operatorRenderer;
		std::shared_ptr<OperatorView> m_operatorView;

		bool m_operatorViewBuilt;
	};
}
