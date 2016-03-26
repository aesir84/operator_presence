#include "stdafx.h"

#include "OpenGLOperatorViewRift.h"

#include "IOperatorViewMediator.h"
#include "IOperatorViewRenderer.h"

#include "scope_guard.h"

namespace operator_view
{
	namespace opengl
	{
		Rift::Rift(std::shared_ptr<IRenderer> renderer, std::shared_ptr<IMediator> mediator)
			: m_renderer(renderer)
			, m_mediator(mediator)
			, m_windowId(0)
		{
			m_mediator->registerDevice(this);
		}

		Rift::~Rift()
		{
			finishOculusVR();
		}

		void Rift::initialize()
		{
			startOculusVR();

			std::uint16_t const width = m_ovrHMDDescriptor.Resolution.w;
			std::uint16_t const height = m_ovrHMDDescriptor.Resolution.h;

			m_renderer->initialize(width, height);

			// Make sure the mediator has already set a proper value in this member.
			//
			assert(m_windowId != 0);

			// TODO: configure Oculus Rift rendering...
		}

		void Rift::render()
		{
			// TODO: update the headset orientation
			// TODO: render
		}

		void Rift::startOculusVR()
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
			auto ovrCreationReverse = helpers::guard_scope([this] { ovr_Destroy(m_ovrSession); });

			m_ovrHMDDescriptor = ovr_GetHmdDesc(m_ovrSession);

			ovrCreationReverse.dismiss();
			ovrInitializationReverse.dismiss();
		}

		void Rift::finishOculusVR()
		{
			ovr_Destroy(m_ovrSession);
			ovr_Shutdown();
		}

		void Rift::setWindowId(std::uint32_t windowId)
		{
			m_windowId = windowId;
		}
	}
}
