#pragma once

namespace operator_view
{
	class IRenderer
	{
	public:
		virtual ~IRenderer() { }

	public:
		virtual void initialize() = 0;

		virtual void renderLeftEye() = 0;
		virtual void renderRightEye() = 0;
	};
}
