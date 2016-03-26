#pragma once

#include "IOperatorViewRift.h"

namespace operator_view
{
	class IMediator;
	class IRenderer;
}

namespace operator_view
{
	namespace opengl
	{
		class Rift : public IRift
		{
			friend class Factory;

		private:
			Rift(std::shared_ptr<IRenderer> renderer, std::shared_ptr<IMediator> mediator);

		public:
			~Rift();

		private:
			std::shared_ptr<IRenderer> m_renderer;
			std::shared_ptr<IMediator> m_mediator;

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
			virtual void setWindowId(std::uint32_t windowId) override;

		private:
			std::uint32_t m_windowId;
		};
	}
}
