#pragma once

#include "IImageInputStreamFilter.h"

namespace helpers
{
	template<typename T>
	class threadsafe_queue;
}

namespace operator_model
{
	namespace utils
	{
		class ImageInputStreamSharer : public IImageInputStreamFilter
		{
		public:
			ImageInputStreamSharer(std::shared_ptr<IImageInputStream> imageInputStreamToFilter, std::shared_ptr<helpers::threadsafe_queue<QImage>> sharepoint);

		public:
			virtual std::shared_ptr<QImage> read() override;

		private:
			std::shared_ptr<helpers::threadsafe_queue<QImage>> m_sharepoint;
		};
	}
}
