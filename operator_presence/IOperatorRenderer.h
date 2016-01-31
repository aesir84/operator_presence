#pragma once

namespace operator_view
{
	class IOperatorRenderer
	{
	public:
		virtual ~IOperatorRenderer() { }

	public:
		virtual void initialize(std::uint16_t eyeResolutionWidth = 0, std::uint16_t eyeResolutionHeight = 0) = 0;

		virtual void renderLeftEye() = 0;
		virtual void renderRightEye() = 0;
	};
}
