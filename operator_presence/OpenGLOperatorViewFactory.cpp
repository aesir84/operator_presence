#include "stdafx.h"

#include "OpenGLOperatorViewFactory.h"

#include "OpenGLOperatorDisplayRenderer.h"
#include "OpenGLOperatorOculusRiftStrategy.h"
#include "OpenGLOperatorVisionDecorator.h"

namespace operator_view
{
	namespace opengl
	{
		std::shared_ptr<IOperatorDisplayRenderer> OperatorViewFactory::createOperatorDisplayRenderer(std::shared_ptr<operator_controller::IOperatorController> controller)
		{
			return std::shared_ptr<IOperatorDisplayRenderer>(new OperatorDisplayRenderer(controller));
		}

		std::shared_ptr<IOperatorOculusRiftStrategy> OperatorViewFactory::createOperatorOculusRiftStrategy(std::shared_ptr<IOperatorViewRenderer> renderer, std::shared_ptr<operator_controller::IOperatorController> controller)
		{
			return std::shared_ptr<IOperatorOculusRiftStrategy>(new OperatorOculusRiftStrategy(renderer, controller));
		}

		std::shared_ptr<IOperatorVisionDecorator> OperatorViewFactory::createOperatorVisionDecorator(std::shared_ptr<IOperatorViewRenderer> decoratedRenderer)
		{
			return std::shared_ptr<IOperatorVisionDecorator>(new OperatorVisionDecorator(decoratedRenderer));
		}
	}
}
