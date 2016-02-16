#pragma once

#include "ImageType.h"

namespace operator_model
{
	namespace utils
	{
		class IImageInputStream
		{
		public:
			virtual ~IImageInputStream() { }

		public:
			virtual Image read() = 0;
		};
	}
}
