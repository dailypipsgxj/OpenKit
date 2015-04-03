#ifndef __QUANTKIT_DATAFILE_H__
#define __QUANTKIT_DATAFILE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <Dictionary>
#include <QString>
#include <FileMode>
#include <QVariant>
#include <Stream>
#include <QList>
#include <MemoryStream>
#include <QByteArray>
#include <QSharedDataPointer>

namespace QuantKit {

class DataFilePrivate;

class ObjectKey;
class StreamerManager;

class QUANTKIT_EXPORT DataFile
{
public:
	DataFile(const QString& name, const StreamerManager& streamerManager);
	~DataFile();

	DataFile(const DataFile &other);
	DataFile& operator=(const DataFile &other);
	bool operator==(const DataFile &other) const;
	inline bool operator!=(const DataFile &other) const { return !(this->operator==(other));  }
public:
	long long_0() const;
	void setLong_0(long value);

	long long_1() const;
	void setLong_1(long value);

	long aCdHfUdLo6() const;
	void setACdHfUdLo6(long value);

	long long_2() const;
	void setLong_2(long value);

	int int_0() const;
	void setInt_0(int value);

	int int_1() const;
	void setInt_1(int value);

	int int_2() const;
	void setInt_2(int value);

	int int_3() const;
	void setInt_3(int value);

	Stream stream_0() const;
	void setStream_0(Stream value);

	bool bool_0() const;
	void setBool_0(bool value);

	bool bool_1() const;
	void setBool_1(bool value);
	QString string_1() const;

	StreamerManager streamerManager_0() const;
	Dictionary<QString,ObjectKey> keys() const;
	unsigned char compressionMethod() const;
	void setCompressionMethod(unsigned char value);
	unsigned char compressionLevel() const;
	void setCompressionLevel(unsigned char value);
	void close();
	void delete(const QString& name);
	void dispose();
	void dump();
	void flush();
	QVariant get(const QString& name);
	void open(FileMode mode = 4);
	void refresh();
	void write(const QString& name, const QVariant& obj);

protected:
	DataFile(DataFilePrivate& dd);
	QSharedDataPointer<DataFilePrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const DataFile& datafile);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataFile& datafile);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataFile)

#endif // __QUANTKIT_DATAFILE_H__
