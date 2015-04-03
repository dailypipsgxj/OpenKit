#ifndef __QUANTKIT_DATAFILESERVERCLIENT_H__
#define __QUANTKIT_DATAFILESERVERCLIENT_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <TcpClient>
#include <QVariant>
#include <Thread>
#include <QSharedDataPointer>

namespace QuantKit {

class DataFileServerClientPrivate;

class FileManager;

class QUANTKIT_EXPORT DataFileServerClient
{
public:
	DataFileServerClient(const TcpClient& client, const FileManager& fileManager);
	~DataFileServerClient();

	DataFileServerClient(const DataFileServerClient &other);
	DataFileServerClient& operator=(const DataFileServerClient &other);
	bool operator==(const DataFileServerClient &other) const;
	inline bool operator!=(const DataFileServerClient &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<DataFileServerClientPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const DataFileServerClient& datafileserverclient);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataFileServerClient& datafileserverclient);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataFileServerClient)

#endif // __QUANTKIT_DATAFILESERVERCLIENT_H__
