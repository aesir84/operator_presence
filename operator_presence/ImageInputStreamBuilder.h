#pragma once

#include "ImageType.h"

namespace operator_model
{
	namespace utils
	{
		class IImageInputStream;
	}
}

namespace operator_model
{
	namespace utils
	{
		class ImageInputStreamBuilder
		{
		protected:
			ImageInputStreamBuilder(std::shared_ptr<IImageInputStream> stream);

		public:
			void rotateImage(double angle);
			void shareImage(std::shared_ptr<helpers::threadsafe_queue<Image>> sharepoint);

		public:
			std::shared_ptr<IImageInputStream> build();

		private:
			std::shared_ptr<IImageInputStream> m_stream;
		};
	}
}
