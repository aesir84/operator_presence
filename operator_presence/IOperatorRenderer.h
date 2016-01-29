#pragma once

namespace operator_view
{
	class IOperatorRenderer
	{
	public:
		virtual ~IOperatorRenderer() { }

	public:
		virtual void initialize() = 0;

		virtual void renderLeftEye() = 0;
		virtual void renderRightEye() = 0;
	};
}
