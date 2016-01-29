#include "stdafx.h"

#include "RendererDecorator.h"

namespace operator_view
{
	RendererDecorator::RendererDecorator(std::shared_ptr<IOperatorRenderer> rendererToDecorate)
		: m_decoratedRenderer(rendererToDecorate)
	{ }
}
