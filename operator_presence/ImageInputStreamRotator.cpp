#include "stdafx.h"

#include "ImageInputStreamRotator.h"

namespace operator_model
{
	namespace utils
	{
		ImageInputStreamRotator::ImageInputStreamRotator(std::shared_ptr<IImageInputStream> imageInputStreamToFilter, double angle)
			: IImageInputStreamFilter(imageInputStreamToFilter)
		{
			m_rotator.rotate(angle);
		}

		Image ImageInputStreamRotator::read()
		{
			return m_filteredImageInputStream->read().transformed(m_rotator);
		}
	}
}
