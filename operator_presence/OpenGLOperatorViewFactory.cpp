#include "stdafx.h"

#include "OpenGLOperatorRendererFactory.h"

#include "OpenGLOperatorDisplayRenderer.h"
#include "OpenGLOperatorVisionRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		std::shared_ptr<IOperatorDisplayRenderer> OperatorRendererFactory::createOperatorDisplayRenderer(std::shared_ptr<IOperatorViewMediator> operatorViewMediator)
		{
			return std::shared_ptr<IOperatorDisplayRenderer>(new OperatorDisplayRenderer(operatorViewMediator));
		}

		std::shared_ptr<IOperatorVisionRenderer> OperatorRendererFactory::createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate, std::shared_ptr<IOperatorViewMediator> operatorViewMediator)
		{
			return std::shared_ptr<IOperatorVisionRenderer>(new OperatorVisionRenderer(operatorRendererToDecorate, operatorViewMediator));
		}
	}
}
