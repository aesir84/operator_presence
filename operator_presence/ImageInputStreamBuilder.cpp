#include "stdafx.h"

#include "ImageInputStreamBuilder.h"

#include "ImageInputStreamRotator.h"
#include "ImageInputStreamSharer.h"
#include "ImageType.h"

namespace operator_model
{
	namespace utils
	{
		ImageInputStreamBuilder::ImageInputStreamBuilder(std::shared_ptr<IImageInputStream> stream)
			: m_stream(stream)
		{ }

		void ImageInputStreamBuilder::rotateImage(double angle)
		{
			m_stream = std::make_shared<ImageInputStreamRotator>(m_stream, angle);
		}

		void ImageInputStreamBuilder::shareImage(std::shared_ptr<helpers::threadsafe_queue<Image>> sharepoint)
		{
			m_stream = std::make_shared<ImageInputStreamSharer>(m_stream, sharepoint);
		}

		std::shared_ptr<IImageInputStream> ImageInputStreamBuilder::build()
		{
			return m_stream;
		}
	}
}
