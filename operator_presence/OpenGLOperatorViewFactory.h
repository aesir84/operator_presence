#pragma once

#include "IOperatorViewFactory.h"

namespace operator_view
{
	namespace opengl
	{
		class Factory : public IFactory
		{
		private:
			virtual std::shared_ptr<IRift> createRift(std::shared_ptr<IRenderer> renderer, std::shared_ptr<IMediator> mediator) override;
			virtual std::shared_ptr<IVision> createVision(std::shared_ptr<IRenderer> decoratedRenderer) override;
			virtual std::shared_ptr<IWindow> createWindow(std::shared_ptr<IMediator> mediator) override;
		};
	}
}
