#pragma once

namespace operator_view
{
	class IOperatorView
	{
	public:
		virtual ~IOperatorView() { }

	public:
		virtual void initialize() = 0;
		virtual void render() = 0;
	};
}
