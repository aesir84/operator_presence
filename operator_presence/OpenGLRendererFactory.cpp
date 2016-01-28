#include "stdafx.h"

#include "OpenGLRendererFactory.h"

#include "IObservableOperatorVision.h"
#include "OpenGLOperatorVisionRenderer.h"

namespace view
{
	namespace opengl
	{
		std::shared_ptr<IRenderer> RendererFactory::createOperatorVisionRenderer(operator_model::IObservableOperatorVision & operatorVision)
		{
			auto operatorVisionRenderer = std::shared_ptr<OperatorVisionRenderer>(new OperatorVisionRenderer);
			operatorVision.registerObserver(std::static_pointer_cast<operator_model::IOperatorVisionObserver>(operatorVisionRenderer));

			return operatorVisionRenderer;
		}
	}
}
