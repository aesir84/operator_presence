#pragma once

namespace operator_model
{
	class IOperatorModel;
}

namespace operator_view
{
	class IOperatorRendererFactory;
	class IOperatorView;
	class IOperatorViewObserver;
}

namespace operator_view
{
	class OperatorViewBuilder
	{
	protected:
		OperatorViewBuilder(std::unique_ptr<IOperatorRendererFactory> factory);

	public:
		std::shared_ptr<IOperatorView> build(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<IOperatorViewObserver> observer);

	private:
		std::unique_ptr<IOperatorRendererFactory> m_factory;
	};
}
