#pragma once

#include "ImageInputStreamBuilder.h"

namespace operator_model
{
	namespace utils
	{
		class WebcamImageInputStreamBuilder : public ImageInputStreamBuilder
		{
		public:
			explicit WebcamImageInputStreamBuilder(std::uint8_t device);
		};
	}
}
