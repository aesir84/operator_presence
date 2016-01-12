#pragma once

namespace view
{
	class IRenderer
	{
	public:
		virtual ~IRenderer() { }

	public:
		virtual void render() = 0;
	};
}
