#pragma once

namespace hmd_view
{
	class IRiftHMDRenderer
	{
	public:
		virtual ~IRiftHMDRenderer() { }

	public:
		virtual void render() = 0;
		virtual void shutdown() = 0;
	};
}
