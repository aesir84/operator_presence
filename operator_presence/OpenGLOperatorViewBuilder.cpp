#include "stdafx.h"

#include "OpenGLOperatorViewBuilder.h"

#include "OpenGLOperatorRendererFactory.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorViewBuilder::OperatorViewBuilder()
			: operator_view::OperatorViewBuilder(std::make_unique<OperatorRendererFactory>())
		{ }
	}
}
