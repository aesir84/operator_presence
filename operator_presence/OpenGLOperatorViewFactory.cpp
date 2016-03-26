#include "stdafx.h"

#include "OpenGLOperatorViewFactory.h"

#include "OpenGLOperatorViewRift.h"
#include "OpenGLOperatorViewVision.h"
#include "OpenGLOperatorViewWindow.h"

namespace operator_view
{
	namespace opengl
	{
		std::shared_ptr<IRift> Factory::createRift(std::shared_ptr<IRenderer> renderer, std::shared_ptr<IMediator> mediator)
		{
			return std::shared_ptr<IRift>(new Rift(renderer, mediator));
		}

		std::shared_ptr<IVision> Factory::createVision(std::shared_ptr<IRenderer> decoratedRenderer)
		{
			return std::shared_ptr<IVision>(new Vision(decoratedRenderer));
		}

		std::shared_ptr<IWindow> Factory::createWindow(std::shared_ptr<IMediator> mediator)
		{
			return std::shared_ptr<IWindow>(new Window(mediator));
		}
	}
}
