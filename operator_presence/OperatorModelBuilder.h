#pragma once

namespace operator_model
{
	class IMediator;
	class IOperatorModel;
}

namespace operator_model
{
	class Builder
	{
	public:
		Builder(std::shared_ptr<IMediator> mediator);
		~Builder();

	private:
		std::shared_ptr<IMediator> m_mediator;

	public:
		std::shared_ptr<IOperatorModel> build();

	private:
		std::shared_ptr<IOperatorModel> m_model;
	};
}
