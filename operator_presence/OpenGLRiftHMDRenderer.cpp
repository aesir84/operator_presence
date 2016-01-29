#include "stdafx.h"

#include "OpenGLRiftHMDRenderer.h"

#include "IOperatorRenderer.h"

namespace hmd_view
{
	namespace opengl
	{
		RiftHMDRenderer::RiftHMDRenderer(std::shared_ptr<operator_view::IOperatorRenderer> operatorRenderer)
			: m_shutdown(false)
		{ }

		void RiftHMDRenderer::render()
		{
			while (!m_shutdown)
			{

			}
		}

		void RiftHMDRenderer::shutdown()
		{
			m_shutdown = true;
		}
	}
}
