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
		virtual void resize(std::uint16_t width, std::uint16_t height) = 0;
	};
}
