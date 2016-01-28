#pragma once

#include "IRendererFactory.h"

namespace operator_view
{
	namespace opengl
	{
		class RendererFactory : public IRendererFactory
		{
		private:
			virtual std::shared_ptr<IRenderer> createOperatorVisionRenderer(operator_model::IObservableOperatorVision & operatorVision) override;
		};
	}
}
