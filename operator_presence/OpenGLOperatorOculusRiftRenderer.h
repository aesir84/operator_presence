#pragma once

#include "IOperatorOculusRiftRenderer.h"

namespace operator_view
{
	class IOperatorRenderer;
	class IOperatorViewMediator;
}

namespace operator_view
{
	namespace opengl
	{
		class OperatorOculusRiftRenderer : public IOperatorOculusRiftRenderer
		{
			friend class OperatorViewRendererFactory;

		private:
			OperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRenderer, std::shared_ptr<IOperatorViewMediator> operatorViewMediator);

		public:
			~OperatorOculusRiftRenderer();

		private:
			std::shared_ptr<IOperatorRenderer> m_operatorRenderer;
			std::shared_ptr<IOperatorViewMediator> m_operatorViewMediator;

		private:
			virtual void initialize() override;
			virtual void render() override;

		private:
			void startOculusVR();

		private:
			ovrSession m_ovrSession;
			ovrGraphicsLuid m_luid;
			ovrHmdDesc m_ovrHMDDescriptor;
		};
	}
}
