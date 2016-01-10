#pragma once

namespace model
{
	class Operator
	{
		Q_OBJECT

	public:
		using EyeImage = std::shared_ptr<QImage>;

	public:
		void updateLeftEyeImage(EyeImage eyeImage);
		void updateRightEyeImage(EyeImage eyeImage);

	Q_SIGNALS:
		void leftEyeImageUpdated(EyeImage image);
		void rightEyeImageUpdated(EyeImage image);

	private:
		EyeImage m_leftEyeImage;
		EyeImage m_rightEyeImage;
	};
}

