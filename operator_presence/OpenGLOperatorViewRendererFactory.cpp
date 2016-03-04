#include "stdafx.h"

#include "OpenGLOperatorViewRendererFactory.h"

#include "OpenGLOperatorOculusRiftRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		std::shared_ptr<IOperatorOculusRiftRenderer> OperatorViewRendererFactory::createOperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRenderer, std::shared_ptr<IOperatorViewMediator> operatorViewMediator)
		{
			return std::shared_ptr<IOperatorOculusRiftRenderer>(new OperatorOculusRiftRenderer(operatorRenderer, operatorViewMediator));
		}
	}
}
