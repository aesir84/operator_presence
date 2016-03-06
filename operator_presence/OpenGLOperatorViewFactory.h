#pragma once

#include "IOperatorViewFactory.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorViewFactory : public IOperatorViewFactory
		{
		private:
			virtual std::shared_ptr<IOperatorDisplayRenderer> createOperatorDisplayRenderer(std::shared_ptr<operator_controller::IOperatorController> controller) override;
			virtual std::shared_ptr<IOperatorOculusRiftStrategy> createOperatorOculusRiftStrategy(std::shared_ptr<IOperatorViewRenderer> renderer, std::shared_ptr<operator_controller::IOperatorController> controller) override;
			virtual std::shared_ptr<IOperatorVisionDecorator> createOperatorVisionDecorator(std::shared_ptr<IOperatorViewRenderer> decoratedRenderer) override;
		};
	}
}
