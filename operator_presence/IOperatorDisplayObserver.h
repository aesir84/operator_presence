#pragma once

namespace operator_view
{
	class IOperatorDisplayObserver
	{
	public:
		virtual ~IOperatorDisplayObserver() { }

	public:
		virtual void updateKeyPressed(Qt::Key key) = 0;
		virtual void updateSizeChanged(std::uint16_t newWidth, std::uint16_t newHeight) = 0;
	};
}
