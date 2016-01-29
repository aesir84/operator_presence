#pragma once

#include "IRiftHMDRenderer.h"

namespace operator_view
{
	class IOperatorRenderer;
}

namespace hmd_view
{
	namespace opengl
	{
		class RiftHMDRenderer : public IRiftHMDRenderer
		{
			friend class HMDRendererFactory;

		private:
			explicit RiftHMDRenderer(std::shared_ptr<operator_view::IOperatorRenderer> operatorRenderer);

		private:
			std::shared_ptr<operator_view::IOperatorRenderer> m_operatorRenderer;

		private:
			virtual void render() override;
			virtual void shutdown() override;

		private:
			std::atomic<bool> m_shutdown;
		};
	}
}
