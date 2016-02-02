#pragma once

namespace operator_view
{
	class IOperatorView
	{
	public:
		virtual ~IOperatorView() { }

	public:
		virtual void open() = 0;
		virtual void close() = 0;

		virtual void exec() = 0;
	};
}
