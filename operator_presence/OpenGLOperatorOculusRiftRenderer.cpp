#include "stdafx.h"

#include "OpenGLOperatorOculusRiftRenderer.h"

#include "scope_guard.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorOculusRiftRenderer::OperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
			: IOperatorOculusRiftRenderer(operatorRendererToDecorate)
		{ }

		OperatorOculusRiftRenderer::~OperatorOculusRiftRenderer()
		{
			ovr_Shutdown();
		}

		void OperatorOculusRiftRenderer::exec()
		{
			try
			{
				startOculusVR();

				std::uint16_t const eyeResolutionWidth = m_ovrHMDDescriptor.Resolution.w / 2; // divide by two because OVR gives the resolution width for both eyes
				std::uint16_t const eyeResolutionHeight = m_ovrHMDDescriptor.Resolution.h;

				initialize(eyeResolutionWidth, eyeResolutionHeight);
			}
			catch (...)
			{

			}
		}

		void OperatorOculusRiftRenderer::shutdown()
		{
		}

		void OperatorOculusRiftRenderer::initialize(std::uint16_t eyeResolutionWidth, std::uint16_t eyeResolutionHeight)
		{
			// Delegate initialization to the decorated objects.
			//
			m_decoratedOperatorRenderer->initialize(eyeResolutionWidth, eyeResolutionHeight);
		}

		void OperatorOculusRiftRenderer::renderLeftEye()
		{
			// Delegate the rendering of the left eye to the decorated object.
			//
			m_decoratedOperatorRenderer->renderLeftEye();
		}

		void OperatorOculusRiftRenderer::renderRightEye()
		{
			// Delegate the rendering of the right eye to the decorated object.
			//
			m_decoratedOperatorRenderer->renderRightEye();
		}

		void OperatorOculusRiftRenderer::startOculusVR()
		{
			ovrResult result = ovrSuccess;

			result = ovr_Initialize(nullptr);

			if (OVR_FAILURE(result))
			{
				ovrErrorInfo errorInfo;
				ovr_GetLastErrorInfo(&errorInfo);

				// TODO: throw an appropriate exception
			}
			auto ovrInitializationReverse = helpers::guard_scope([] { ovr_Shutdown(); });

			result = ovr_Create(&m_ovrSession, &m_luid);

			if (OVR_FAILURE(result))
			{
				ovrErrorInfo errorInfo;
				ovr_GetLastErrorInfo(&errorInfo);

				// TODO: throw an appropriate exception
			}
			auto ovrCreationReverse = helpers::guard_scope([this] {ovr_Destroy(m_ovrSession); });

			m_ovrHMDDescriptor = ovr_GetHmdDesc(m_ovrSession);

			ovrCreationReverse.dismiss();
			ovrInitializationReverse.dismiss();
		}
	}
}
