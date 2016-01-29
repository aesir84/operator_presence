#include "stdafx.h"

#include "OpenGLRendererFactory.h"

#include "OpenGLOperatorVisionRenderer.h"
#include "OpenGLWindowRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		std::shared_ptr<IOperatorRenderer> RendererFactory::createWindowRenderer()
		{
			return std::shared_ptr<WindowRenderer>(new WindowRenderer);
		}

		std::shared_ptr<IOperatorRenderer> RendererFactory::createOperatorVisionRenderer(std::shared_ptr<IOperatorRenderer> rendererToDecorate)
		{
			return std::shared_ptr<OperatorVisionRenderer>(new OperatorVisionRenderer(rendererToDecorate));
		}
	}
}
