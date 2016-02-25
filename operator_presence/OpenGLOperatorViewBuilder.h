#pragma once

#include "OperatorViewBuilder.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorViewBuilder : public operator_view::OperatorViewBuilder
		{
		public:
			OperatorViewBuilder(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<IOperatorViewObserver> observer);
		};
	}
}
