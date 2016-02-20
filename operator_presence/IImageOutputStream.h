#pragma once

#include "ImageType.h"

namespace operator_model
{
	namespace utils
	{
		class IImageOutputStream
		{
		public:
			virtual ~IImageOutputStream() { }

		public:
			virtual void write(Image image) = 0;
		};
	}
}
