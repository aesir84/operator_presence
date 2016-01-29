#include "stdafx.h"

#include "OpenGLOperatorRendererFactory.h"

#include "OpenGLOperatorVisionRenderer.h"
#include "OpenGLOperatorRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		std::shared_ptr<IOperatorRenderer> OperatorRendererFactory::createOperatorRenderer()
		{
			return std::shared_ptr<OperatorRenderer>(new OperatorRenderer);
		}

		std::shared_ptr<IOperatorRenderer> OperatorRendererFactory::createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
		{
			return std::shared_ptr<OperatorVisionRenderer>(new OperatorVisionRenderer(operatorRendererToDecorate));
		}
	}
}
