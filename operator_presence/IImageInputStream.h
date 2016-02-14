#pragma once

namespace operator_model
{
	namespace utils
	{
		class IImageInputStream
		{
		public:
			virtual ~IImageInputStream() { }

		public:
			virtual std::shared_ptr<QImage> read() = 0;
		};
	}
}
