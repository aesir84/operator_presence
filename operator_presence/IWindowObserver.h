#pragma once

namespace model
{
	class IWindowObserver
	{
	public:
		virtual ~IWindowObserver() { }

	public:
		virtual void updateSize(QSize const & size) = 0;
	};
}
