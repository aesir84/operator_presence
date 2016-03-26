#include "stdafx.h"

#include "OpenGLOperatorViewBuilder.h"

#include "OpenGLOperatorViewFactory.h"

namespace operator_view
{
	namespace opengl
	{
		Builder::Builder(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<IMediator> mediator)
			: operator_view::Builder(model, mediator, std::make_unique<Factory>())
		{ }
	}
}
