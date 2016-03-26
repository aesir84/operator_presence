#pragma once

namespace operator_view
{
	class IDevice
	{
	public:
		virtual ~IDevice() { }

	public:
		virtual void initialize() = 0;
		virtual void render() = 0;

	public:
		virtual void setWindowId(std::uint32_t windowId) = 0;
	};
}
