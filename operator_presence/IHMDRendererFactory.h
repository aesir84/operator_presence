#pragma once

namespace hmd_view
{
	class IRiftHMDRenderer;
}

namespace hmd_view
{
	class IHMDRendererFactory
	{
	public:
		virtual ~IHMDRendererFactory() { }

	public:
		virtual std::shared_ptr<IRiftHMDRenderer> createRiftHMDRenderer() = 0;
	};
}
