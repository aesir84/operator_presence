#include "stdafx.h"

#include "OpenGLOperatorOculusRiftStrategy.h"

#include "IOperatorController.h"
#include "IOperatorViewRenderer.h"

#include "scope_guard.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorOculusRiftStrategy::OperatorOculusRiftStrategy(std::shared_ptr<IOperatorViewRenderer> renderer, std::shared_ptr<operator_controller::IOperatorController> controller)
			: m_renderer(renderer)
			, m_controller(controller)
			, m_winId(0)
		{
			m_controller->registerOperatorHeadset(this);
		}

		OperatorOculusRiftStrategy::~OperatorOculusRiftStrategy()
		{
			ovr_Shutdown();
		}

		void OperatorOculusRiftStrategy::initialize()
		{
			startOculusVR();

			std::uint16_t const width = m_ovrHMDDescriptor.Resolution.w;
			std::uint16_t const height = m_ovrHMDDescriptor.Resolution.h;

			m_renderer->initialize(width, height);

			// Make sure the controller has already set a proper value in this member.
			//
			assert(m_winId != 0);

			// TODO: configure Oculus Rift rendering...
		}

		void OperatorOculusRiftStrategy::render()
		{
			// TODO: update the headset orientation
			// TODO: render
		}

		void OperatorOculusRiftStrategy::startOculusVR()
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

		void OperatorOculusRiftStrategy::setWindowId(WId winId)
		{
			m_winId = winId;
		}
	}
}
