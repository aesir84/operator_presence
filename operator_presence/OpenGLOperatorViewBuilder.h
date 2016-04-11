#pragma once

#include "OperatorViewBuilder.h"

namespace operator_view
{
	namespace opengl
	{
		class Builder : public operator_view::Builder
		{
		public:
			Builder(std::shared_ptr<IMediator> mediator);
		};
	}
}
