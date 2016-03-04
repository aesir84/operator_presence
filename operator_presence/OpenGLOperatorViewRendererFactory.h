#pragma once

#include "IOperatorViewRendererFactory.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorViewRendererFactory : public IOperatorViewRendererFactory
		{
		private:
			virtual std::shared_ptr<IOperatorOculusRiftRenderer> createOperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRenderer) override;
		};
	}
}
