#pragma once

#include "IRendererFactory.h"

namespace view
{
	namespace opengl
	{
		class RendererFactory : public IRendererFactory
		{
		private:
			virtual std::shared_ptr<IRenderer> createOperatorVisionRenderer(model::IObservableOperatorVision & operatorVision) override;
		};
	}
}
