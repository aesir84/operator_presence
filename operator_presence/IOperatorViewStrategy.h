#pragma once

namespace operator_view
{
	class IOperatorViewStrategy
	{
	public:
		virtual ~IOperatorViewStrategy() { }

	public:
		virtual void initialize() = 0;
		virtual void render() = 0;
	};
}
