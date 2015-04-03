#ifndef __QUANTKIT_DATAFILESERVERCLIENT__H__
#define __QUANTKIT_DATAFILESERVERCLIENT__H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <TcpClient>
#include <QVariant>
#include <Thread>
#include <QSharedDataPointer>

namespace QuantKit {

class DataFileServerClient_Private;

class DataFileManager;
class DataFile;
class StreamerManager;
class IdArray;
class DataSeries;
class QuickLZ;

class QUANTKIT_EXPORT DataFileServerClient_
{
public:
	DataFileServerClient_(const TcpClient& client, const DataFileManager& fileManager);
	~DataFileServerClient_();

	DataFileServerClient_(const DataFileServerClient_ &other);
	DataFileServerClient_& operator=(const DataFileServerClient_ &other);
	bool operator==(const DataFileServerClient_ &other) const;
	inline bool operator!=(const DataFileServerClient_ &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<DataFileServerClient_Private> d_ptr;

	friend QDebug operator<<(QDebug dbg, const DataFileServerClient_& datafileserverclient_);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataFileServerClient_& datafileserverclient_);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataFileServerClient_)

#endif // __QUANTKIT_DATAFILESERVERCLIENT__H__
