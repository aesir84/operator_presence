#pragma once

#include "IImageInputStream.h"

namespace operator_model
{
	namespace utils
	{
		class IImageInputStreamFilter : public IImageInputStream
		{
		public:
			IImageInputStreamFilter(std::shared_ptr<IImageInputStream> imageInputStreamToFilter)
				: m_filteredImageInputStream(imageInputStreamToFilter)
			{ }

		protected:
			std::shared_ptr<IImageInputStream> m_filteredImageInputStream;
		};
	}
}
