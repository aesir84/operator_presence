#pragma once

namespace helpers
{
	template<typename T>
	class threadsafe_queue;
}

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
			void shareImage(std::shared_ptr<helpers::threadsafe_queue<QImage>> sharepoint);

		public:
			std::shared_ptr<IImageInputStream> build();

		private:
			std::shared_ptr<IImageInputStream> m_stream;
		};
	}
}
