#include "stdafx.h"

#include "OpenGLOperatorViewBuilder.h"

#include "OpenGLOperatorRendererFactory.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorViewBuilder::OperatorViewBuilder(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<IOperatorViewObserver> observer)
			: operator_view::OperatorViewBuilder(model, observer, std::make_unique<OperatorRendererFactory>())
		{ }
	}
}
