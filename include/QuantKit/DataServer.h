#ifndef __QUANTKIT_DATASERVER_H__
#define __QUANTKIT_DATASERVER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/SaveMode.h>
#include <QuantKit/BarType.h>

namespace QuantKit {

class DataServerPrivate;

class Framework;
class Instrument;
class DataObject;
class DataSeries;

class QUANTKIT_EXPORT DataServer
{
public:
	explicit DataServer(const Framework& framework);
	~DataServer();

	DataServer(const DataServer &other);
	DataServer& operator=(const DataServer &other);
	bool operator==(const DataServer &other) const;
	inline bool operator!=(const DataServer &other) const { return !(this->operator==(other));  }
public:
	bool tapeMode() const;
	void setTapeMode(bool value);
	DataSeries addDataSeries(const Instrument& instrument, unsigned char type, BarType barType = BarType::Time, long barSize = 60);
	DataSeries addDataSeries(const QString& name);
	void close();
	void deleteDataSeries(const Instrument& instrument, unsigned char type, BarType barType = BarType::Time, long barSize = 60);
	void deleteDataSeries(const QString& name);
	void flush();
	DataSeries getDataSeries(const Instrument& instrument, unsigned char type, BarType barType = BarType::Time, long barSize = 60);
	DataSeries getDataSeries(const QString& name);
	QList<DataSeries> getDataSeriesList(const Instrument& instrument = 0, const QString& pattern = "");
	void open();
	void save(const Instrument& instrument, const DataObject& obj, SaveMode option = SaveMode::Add);

protected:
	DataServer(DataServerPrivate& dd);
	QSharedDataPointer<DataServerPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const DataServer& dataserver);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataServer& dataserver);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataServer)

#endif // __QUANTKIT_DATASERVER_H__
