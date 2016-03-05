#include "stdafx.h"

#include "OpenGLOperatorOculusRiftStrategy.h"

#include "IOperatorViewObserver.h"
#include "IOperatorViewRenderer.h"

#include "scope_guard.h"

namespace operator_view
{
	namespace opengl
	{
		OperatorOculusRiftStrategy::OperatorOculusRiftStrategy(std::shared_ptr<IOperatorViewRenderer> renderer)
			: m_renderer(renderer)
		{ }

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

			// TODO: configure Oculus Rift rendering...
		}

		void OperatorOculusRiftStrategy::render()
		{
			// TODO: notify the headset orientation
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

		void OperatorOculusRiftStrategy::registerObserver(std::shared_ptr<IOperatorViewObserver> observer)
		{
			m_observers.push_back(observer);
		}

		void OperatorOculusRiftStrategy::notifyHeadsetOrientationChanged(double yaw, double pitch, double roll)
		{
			for (auto & observer : m_observers)
			{
				auto existingObserver = observer.lock();

				if (existingObserver)
				{
					existingObserver->updateHeadsetOrientationChanged(yaw, pitch, roll);
				}
			}
		}
	}
}
