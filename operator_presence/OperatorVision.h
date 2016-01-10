#pragma once

namespace model
{
	class Operator : public QObject
	{
		Q_OBJECT

	public:
		Operator();

	public:
		void updatePosition(QVector3D const & position);

		void updateLeftEyeImage(QImage const & eyeImage);
		void updateRightEyeImage(QImage const & eyeImage);

	Q_SIGNALS:
		void positionUpdated(QVector3D const & position);

		void leftEyeImageUpdated(QImage const & image);
		void rightEyeImageUpdated(QImage const & image);

	private:
		QVector3D m_position;

		QImage m_leftEyeImage;
		QImage m_rightEyeImage;
	};
}

