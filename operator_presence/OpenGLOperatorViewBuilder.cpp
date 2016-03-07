#include "stdafx.h"

#include "OpenGLOperatorViewBuilder.h"

#include "OpenGLOperatorViewFactory.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorViewBuilder::OperatorViewBuilder(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<operator_controller::IOperatorController> controller)
			: operator_view::OperatorViewBuilder(model, controller, std::make_unique<OperatorViewFactory>())
		{ }
	}
}
