#ifndef __QUANTKIT_DATASERIESNAMEHELPER_H__
#define __QUANTKIT_DATASERIESNAMEHELPER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

#include <QuantKit/BarType.h>

namespace QuantKit {

class DataSeriesNameHelperPrivate;

class Instrument;
class DataSeries;
class Framework;

class QUANTKIT_EXPORT DataSeriesNameHelper
{
public:
	~DataSeriesNameHelper();

	DataSeriesNameHelper(const DataSeriesNameHelper &other);
	DataSeriesNameHelper& operator=(const DataSeriesNameHelper &other);
	bool operator==(const DataSeriesNameHelper &other) const;
	inline bool operator!=(const DataSeriesNameHelper &other) const { return !(this->operator==(other));  }
public:
	unsigned char getDataType(const DataSeries& series);
	Instrument getInstrument(const DataSeries& series, const Framework& framework);
	QString getName(const Instrument& instrument, unsigned char type);
	QString getName(const Instrument& instrument, BarType barType, long barSize);
	QString getSymbol(const DataSeries& series);
	QString getSymbol(const QString& seriesName);
	bool tryGetBarTypeSize(const DataSeries& series, BarType& barType, const Int64&& barSize);

private:
	QSharedDataPointer<DataSeriesNameHelperPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const DataSeriesNameHelper& dataseriesnamehelper);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataSeriesNameHelper& dataseriesnamehelper);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataSeriesNameHelper)

#endif // __QUANTKIT_DATASERIESNAMEHELPER_H__
