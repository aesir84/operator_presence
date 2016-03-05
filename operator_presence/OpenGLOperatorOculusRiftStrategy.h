#pragma once

#include "IOperatorOculusRiftStrategy.h"

namespace operator_view
{
	class IOperatorViewRenderer;
}

namespace operator_view
{
	namespace opengl
	{
		class OperatorOculusRiftStrategy : public IOperatorOculusRiftStrategy
		{
			friend class OperatorViewFactory;

		private:
			explicit OperatorOculusRiftStrategy(std::shared_ptr<IOperatorViewRenderer> renderer);

		public:
			~OperatorOculusRiftStrategy();

		private:
			std::shared_ptr<IOperatorViewRenderer> m_renderer;

		private:
			virtual void initialize() override;
			virtual void render() override;

		private:
			void startOculusVR();

		private:
			ovrSession m_ovrSession;
			ovrGraphicsLuid m_luid;
			ovrHmdDesc m_ovrHMDDescriptor;

		private:
			virtual void registerObserver(std::shared_ptr<IOperatorViewObserver> observer) override;

		private:
			std::vector<std::weak_ptr<IOperatorViewObserver>> m_observers;

		private:
			virtual void notifyHeadsetOrientationChanged(double yaw, double pitch, double roll) override;
		};
	}
}
