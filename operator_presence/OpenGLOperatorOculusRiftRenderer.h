#pragma once

#include "IOperatorOculusRiftRenderer.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorOculusRiftRenderer : public IOperatorOculusRiftRenderer
		{
			friend class OperatorRendererFactory;

		private:
			OperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate);

		public:
			~OperatorOculusRiftRenderer();

		private:
			virtual void exec() override;
			virtual void shutdown() override;

		private:
			virtual void initialize(std::uint16_t eyeResolutionWidth, std::uint16_t eyeResolutionHeight) override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			void startOculusVR();

		private:
			ovrSession m_ovrSession;
			ovrGraphicsLuid m_luid;
			ovrHmdDesc m_ovrHMDDescriptor;
		};
	}
}
