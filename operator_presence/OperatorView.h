#pragma once

#include "IOperatorView.h"

namespace operator_view
{
	class IOperatorViewStrategy;
}

namespace operator_view
{
	class OperatorView : public IOperatorView
	{
		friend class OperatorViewBuilder;

	private:
		OperatorView(std::shared_ptr<IOperatorViewStrategy> viewStrategy);

	private:
		std::shared_ptr<IOperatorViewStrategy> m_viewStrategy;

	private:
		virtual void initialize() override;
		virtual void render() override;
	};
}
