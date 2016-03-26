#pragma once

#include "IOperatorHeadset.h"
#include "IOperatorOculusRiftStrategy.h"

namespace operator_controller
{
	class IOperatorController;
}

namespace operator_view
{
	class IOperatorViewRenderer;
}

namespace operator_view
{
	namespace opengl
	{
		class OperatorOculusRiftStrategy : public IOperatorOculusRiftStrategy, public operator_controller::IOperatorHeadset
		{
			friend class OperatorViewFactory;

		private:
			explicit OperatorOculusRiftStrategy(std::shared_ptr<IOperatorViewRenderer> renderer, std::shared_ptr<operator_controller::IOperatorController> controller);

		public:
			~OperatorOculusRiftStrategy();

		private:
			std::shared_ptr<IOperatorViewRenderer> m_renderer;
			std::shared_ptr<operator_controller::IOperatorController> m_controller;

		private:
			virtual void initialize() override;
			virtual void render() override;

		private:
			void startOculusVR();
			void finishOculusVR();

		private:
			ovrSession m_ovrSession;
			ovrGraphicsLuid m_luid;
			ovrHmdDesc m_ovrHMDDescriptor;

		private:
			virtual void setWindowId(WId winId) override;

		private:
			WId m_winId;
		};
	}
}
