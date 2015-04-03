#ifndef __QUANTKIT_BAR_H__
#define __QUANTKIT_BAR_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QDateTime>

#include <QuantKit/DataObject.h>
#include <QuantKit/BarType.h>
#include <QuantKit/BarStatus.h>

namespace QuantKit {

class BarPrivate;

class IdArray;

class QUANTKIT_EXPORT Bar Q_DECL_FINAL : public DataObject
{
public:
	Bar();
	Bar(const QDateTime& openDateTime, const QDateTime& closeDateTime, int instrumentId, BarType type, long size, double open = 0, double high = 0, double low = 0, double close = 0, long volume = 0, long openInt = 0);
	~Bar();

public:
	BarType type() const;
	void setType(BarType value);
	QDateTime closeDateTime() const;
	QDateTime openDateTime() const;
	TimeSpan duration() const;
	int instrumentId() const;
	void setInstrumentId(int value);
	BarStatus status() const;
	void setStatus(BarStatus value);
	double open() const;
	void setOpen(double value);
	double high() const;
	void setHigh(double value);
	double low() const;
	void setLow(double value);
	double close() const;
	void setClose(double value);
	long volume() const;
	void setVolume(long value);
	long openInt() const;
	void setOpenInt(long value);
	long n() const;
	void setN(long value);
	long size() const;
	void setSize(long value);
	double mean() const;
	void setMean(double value);
	double variance() const;
	void setVariance(double value);
	double stdDev() const;
	double range() const;
	double median() const;
	double typical() const;
	double weighted() const;
	double average() const;
	double item(unsigned char index) const;
	void setItem(unsigned char index, double value);
	double item(const QString& name) const;
	void setItem(const QString& name, double value);
	void addField(const QString& name, unsigned char index);

private:
	QK_DECLARE_PRIVATE(Bar)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Bar)

#endif // __QUANTKIT_BAR_H__
