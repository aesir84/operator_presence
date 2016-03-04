#pragma once

#include "IOperatorOculusRiftRenderer.h"

namespace operator_view
{
	class IOperatorRenderer;
}

namespace operator_view
{
	namespace opengl
	{
		class OperatorOculusRiftRenderer : public IOperatorOculusRiftRenderer
		{
			friend class OperatorRendererFactory;

		private:
			OperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRenderer);

		private:
			std::shared_ptr<IOperatorRenderer> m_operatorRenderer;

		public:
			~OperatorOculusRiftRenderer();

		private:
			virtual void initialize() override;
			virtual void render() override;

		private:
			virtual void registerObserver(std::shared_ptr<IOperatorRendererObserver> observer) override;

		private:
			std::vector<std::weak_ptr<IOperatorRendererObserver>> m_observers;

		private:
			virtual void notifyHeadOrientationChanged(double yaw, double pitch, double roll) override;

		private:
			void startOculusVR();

		private:
			ovrSession m_ovrSession;
			ovrGraphicsLuid m_luid;
			ovrHmdDesc m_ovrHMDDescriptor;
		};
	}
}
