#pragma once

namespace hmd_view
{
	class IRiftHMDRenderer;
}

namespace operator_view
{
	class IOperatorRenderer;
}

namespace hmd_view
{
	class IHMDRendererFactory
	{
	public:
		virtual ~IHMDRendererFactory() { }

	public:
		virtual std::shared_ptr<IRiftHMDRenderer> createRiftHMDRenderer(std::shared_ptr<IOperatorRenderer> operatorRenderer) = 0;
	};
}
