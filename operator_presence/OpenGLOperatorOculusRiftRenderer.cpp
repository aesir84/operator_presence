#include "stdafx.h"

#include "OpenGLOperatorOculusRiftRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorOculusRiftRenderer::OperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
			: IOperatorOculusRiftRenderer(operatorRendererToDecorate)
		{ }

		void OperatorOculusRiftRenderer::initialize()
		{
		}

		void OperatorOculusRiftRenderer::renderLeftEye()
		{
		}

		void OperatorOculusRiftRenderer::renderRightEye()
		{
		}
	}
}
