#include "stdafx.h"

#include "ImageInputStreamSharer.h"

namespace operator_model
{
	namespace utils
	{
		ImageInputStreamSharer::ImageInputStreamSharer(std::shared_ptr<IImageInputStream> imageInputStreamToFilter, std::shared_ptr<helpers::threadsafe_queue<Image>> sharepoint)
			: IImageInputStreamFilter(imageInputStreamToFilter)
			, m_sharepoint(sharepoint)
		{ }

		Image ImageInputStreamSharer::read()
		{
			auto imageToFilter = m_filteredImageInputStream->read();

			m_sharepoint->push(imageToFilter);
			return imageToFilter;
		}
	}
}
