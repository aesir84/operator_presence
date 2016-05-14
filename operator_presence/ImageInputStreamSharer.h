#pragma once

#include "IImageInputStreamFilter.h"

namespace operator_model
{
	namespace utils
	{
		class ImageInputStreamSharer : public IImageInputStreamFilter
		{
		public:
			ImageInputStreamSharer(std::shared_ptr<IImageInputStream> imageInputStreamToFilter, std::shared_ptr<helpers::threadsafe_queue<Image>> sharepoint);

		public:
			virtual Image read() override;

		private:
			std::shared_ptr<helpers::threadsafe_queue<Image>> m_sharepoint;
		};
	}
}
