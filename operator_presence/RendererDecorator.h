#pragma once

#include "IRenderer.h"

namespace operator_view
{
	class RendererDecorator : public IRenderer
	{
	public:
		explicit RendererDecorator(std::shared_ptr<IRenderer> rendererToDecorate);
	protected:
		std::shared_ptr<IRenderer> m_decoratedRenderer;
	};
}
