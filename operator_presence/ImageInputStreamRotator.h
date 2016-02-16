#pragma once

#include "IImageInputStreamFilter.h"

namespace operator_model
{
	namespace utils
	{
		class ImageInputStreamRotator : public IImageInputStreamFilter
		{
		public:
			ImageInputStreamRotator(std::shared_ptr<IImageInputStream> imageInputStreamToFilter, double angle);

		public:
			virtual std::shared_ptr<QImage> read() override;

		private:
			QTransform m_rotator;
		};
	}
}
