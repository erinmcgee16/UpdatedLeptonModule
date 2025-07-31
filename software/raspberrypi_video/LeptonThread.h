#ifndef LEPTONTHREAD_H
#define LEPTONTHREAD_H

#include <cstdint>
#include <QThread>
#include <QtGui>
#include <QPixmap>
#include <QImage>

class LeptonThread : public QThread
{
	Q_OBJECT;

public:
	LeptonThread();
	~LeptonThread();

	void setLogLevel(uint16_t newLoglevel);
	void useColormap(int newTypeColormap);
	void useLepton(int newTypeLepton);
	void useSpiSpeedMhz(unsigned int newSpiSpeed);
	void setAutomaticScalingRange();
	void useRangeMinValue(uint16_t newMinValue);
	void useRangeMaxValue(uint16_t newMaxValue);

private:
	void run();
	void log_message(uint16_t level, std::string msg);
	double rawToTemperature(uint16_t rawValue); // Convert raw value to temperature in Celsius

	QImage myImage;

	uint8_t result[164*60];
	uint8_t shelf[4][164*60];
	uint16_t loglevel;
	const int *selectedColormap;
	int selectedColormapSize;
	int typeColormap;
	int typeLepton;
	int myImageWidth;
	int myImageHeight;
	int spiSpeed;
	bool autoRangeMin;
	bool autoRangeMax;
	uint16_t rangeMin;
	uint16_t rangeMax;

public slots:
	void performFFC();

signals:
	void updateImage(QImage);
	void updateTemperature(QString); // New signal for temperature updates
};

#endif // LEPTONTHREAD_H
