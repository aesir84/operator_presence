#include "stdafx.h"

#include "ImageInputStreamSharer.h"

#include "threadsafe_queue.h"

namespace operator_model
{
	namespace utils
	{
		ImageInputStreamSharer::ImageInputStreamSharer(std::shared_ptr<IImageInputStream> imageInputStreamToFilter, std::shared_ptr<helpers::threadsafe_queue<QImage>> sharepoint)
			: IImageInputStreamFilter(imageInputStreamToFilter)
			, m_sharepoint(sharepoint)
		{ }

		std::shared_ptr<QImage> ImageInputStreamSharer::read()
		{
			auto imageToFilter = m_filteredImageInputStream->read();
			m_sharepoint->push(*imageToFilter);
			return imageToFilter;
		}
	}
}
