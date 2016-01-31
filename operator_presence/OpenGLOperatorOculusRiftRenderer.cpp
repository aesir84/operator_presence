#include "stdafx.h"

#include "OpenGLOperatorOculusRiftRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorOculusRiftRenderer::OperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
			: IOperatorOculusRiftRenderer(operatorRendererToDecorate)
		{ }

		void OperatorOculusRiftRenderer::initialize(std::uint16_t eyeResolutionWidth, std::uint16_t eyeResolutionHeight)
		{
			// The HMD will override these values.
			// Therefore, they are not used here.
			//
			Q_UNUSED(eyeResolutionWidth);
			Q_UNUSED(eyeResolutionHeight);
		}

		void OperatorOculusRiftRenderer::renderLeftEye()
		{
		}

		void OperatorOculusRiftRenderer::renderRightEye()
		{
		}
	}
}
