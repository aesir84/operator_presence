#include "stdafx.h"

#include "OpenGLOperatorViewBuilder.h"

#include "OpenGLOperatorViewFactory.h"

namespace operator_view
{
	namespace opengl
	{
		Builder::Builder(std::shared_ptr<IMediator> mediator)
			: operator_view::Builder(mediator, std::make_unique<Factory>())
		{ }
	}
}
