#include "stdafx.h"

#include "OpenGLRendererFactory.h"

#include "IObservableOperatorVision.h"
#include "OpenGLOperatorVisionRenderer.h"

namespace view
{
	namespace opengl
	{
		std::shared_ptr<IRenderer> RendererFactory::createWindowRenderer(model::IObservableWindow & window)
		{
			
		}

		std::shared_ptr<IRenderer> RendererFactory::createOperatorVisionRenderer(model::IObservableOperatorVision & operatorVision)
		{
			auto operatorVisionRenderer = std::shared_ptr<OperatorVisionRenderer>(new OperatorVisionRenderer);
			operatorVision.registerObserver(std::static_pointer_cast<model::IOperatorVisionObserver>(operatorVisionRenderer));

			return operatorVisionRenderer;
		}
	}
}
