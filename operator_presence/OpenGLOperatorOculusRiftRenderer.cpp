#include "stdafx.h"

#include "OpenGLOperatorOculusRiftRenderer.h"

#include "IOperatorRenderer.h"
#include "IOperatorRendererObserver.h"

#include "scope_guard.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorOculusRiftRenderer::OperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRenderer)
			: m_operatorRenderer(operatorRenderer)
		{ }

		OperatorOculusRiftRenderer::~OperatorOculusRiftRenderer()
		{
			ovr_Shutdown();
		}

		void OperatorOculusRiftRenderer::initialize()
		{
			startOculusVR();

			std::uint16_t const eyeResolutionWidth = m_ovrHMDDescriptor.Resolution.w / 2; // divide by two because OVR gives the resolution width for both eyes
			std::uint16_t const eyeResolutionHeight = m_ovrHMDDescriptor.Resolution.h;

			m_operatorRenderer->initialize(eyeResolutionWidth, eyeResolutionHeight);

			// TODO: configure Oculus Rift rendering...
		}

		void OperatorOculusRiftRenderer::render()
		{
			// TODO: render
		}

		void OperatorOculusRiftRenderer::registerObserver(std::shared_ptr<IOperatorRendererObserver> observer)
		{
			m_observers.push_back(observer);
		}

		void OperatorOculusRiftRenderer::notifyHeadOrientationChanged(double yaw, double pitch, double roll)
		{
			for (auto & observer : m_observers)
			{
				auto existingObserver = observer.lock();

				if (existingObserver)
				{
					existingObserver->updateHeadOrientationChanged(yaw, pitch, roll);
				}
			}
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
