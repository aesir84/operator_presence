#include "stdafx.h"

#include "OpenGLOperatorRendererFactory.h"

#include "IObservableOperatorVision.h"
#include "OpenGLOperatorDisplayRenderer.h"
#include "OpenGLOperatorVisionRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		std::shared_ptr<IOperatorDisplayRenderer> OperatorRendererFactory::createOperatorDisplayRenderer()
		{
			return std::shared_ptr<IOperatorDisplayRenderer>(new OperatorDisplayRenderer);
		}

		std::shared_ptr<IOperatorVisionRenderer> OperatorRendererFactory::createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
		{
			return std::shared_ptr<OperatorVisionRenderer>(new OperatorVisionRenderer(operatorRendererToDecorate));
		}
	}
}
