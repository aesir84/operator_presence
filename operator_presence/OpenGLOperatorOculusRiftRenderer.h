#pragma once

#include "IOperatorOculusRiftRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorOculusRiftRenderer : public IOperatorOculusRiftRenderer
		{
			friend class OperatorRendererFactory;

		private:
			OperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate);

		private:
			virtual void initialize() override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;
		};
	}
}
