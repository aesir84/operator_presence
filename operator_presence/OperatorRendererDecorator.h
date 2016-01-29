#pragma once

#include "IOperatorRenderer.h"

namespace operator_view
{
	class RendererDecorator : public IOperatorRenderer
	{
	public:
		explicit RendererDecorator(std::shared_ptr<IOperatorRenderer> rendererToDecorate);
	protected:
		std::shared_ptr<IOperatorRenderer> m_decoratedRenderer;
	};
}
