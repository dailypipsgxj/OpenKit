#ifndef __QUANTKIT_DATAFILESERVER_H__
#define __QUANTKIT_DATAFILESERVER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <IPAddress>
#include <TcpListener>
#include <QSharedDataPointer>

namespace QuantKit {

class DataFileServerPrivate;

class DataFileManager;

class QUANTKIT_EXPORT DataFileServer
{
public:
	DataFileServer(int port, const QString& path);
	~DataFileServer();

	DataFileServer(const DataFileServer &other);
	DataFileServer& operator=(const DataFileServer &other);
	bool operator==(const DataFileServer &other) const;
	inline bool operator!=(const DataFileServer &other) const { return !(this->operator==(other));  }
public:
	void start();
	void stop();

private:
	QSharedDataPointer<DataFileServerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const DataFileServer& datafileserver);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataFileServer& datafileserver);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataFileServer)

#endif // __QUANTKIT_DATAFILESERVER_H__
