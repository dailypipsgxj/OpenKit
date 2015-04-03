#ifndef __QUANTKIT_NETDATAFILE__H__
#define __QUANTKIT_NETDATAFILE__H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QVariant>
#include <QByteArray>
#include <QList>
#include <Thread>

#include <QuantKit/DataFile.h>

namespace QuantKit {

class NetDataFile_Private;

class StreamerManager;
class NetDataSeries;
class DataObject;
class QuickLZ;

class QUANTKIT_EXPORT NetDataFile_ Q_DECL_FINAL : public DataFile
{
public:
	NetDataFile_(const QString& name, const QString& host, int port, const StreamerManager& streamerManager = 0);
	~NetDataFile_();

public:
	void clear(const NetDataSeries& series);
	void refresh(const NetDataSeries& series);

private:
	QK_DECLARE_PRIVATE(NetDataFile_)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::NetDataFile_)

#endif // __QUANTKIT_NETDATAFILE__H__
