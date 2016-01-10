#pragma once

class OperatorVision
{
	Q_OBJECT

public:
	using EyeImage = std::shared_ptr<QImage>;

public:
	OperatorVision();

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
