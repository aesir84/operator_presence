#include "stdafx.h"

#include "OpenGLOperatorViewBuilder.h"

#include "OpenGLOperatorRendererFactory.h"
#include "OpenGLOperatorViewRendererFactory.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorViewBuilder::OperatorViewBuilder(std::shared_ptr<operator_model::IOperatorModel> operatorModel)
			: operator_view::OperatorViewBuilder(operatorModel, std::make_unique<OperatorViewRendererFactory>(), std::make_unique<OperatorRendererFactory>())
		{ }
	}
}
