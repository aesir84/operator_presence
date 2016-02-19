#include "stdafx.h"

#include "WebcamImageInputStreamBuilder.h"

namespace operator_model
{
	namespace utils
	{
		namespace
		{
			std::shared_ptr<IImageInputStream> createWebcamDevice(std::uint8_t device)
			{
				// TODO: add implementation
			}
		}

		WebcamImageInputStreamBuilder::WebcamImageInputStreamBuilder(std::uint8_t device)
			: ImageInputStreamBuilder(createWebcamDevice(device))
		{ }
	}
}
