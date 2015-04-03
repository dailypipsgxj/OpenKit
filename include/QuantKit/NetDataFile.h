#ifndef __QUANTKIT_NETDATAFILE_H__
#define __QUANTKIT_NETDATAFILE_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/DataFile.h>

namespace QuantKit {

class NetDataFilePrivate;

class StreamerManager;

class QUANTKIT_EXPORT NetDataFile Q_DECL_FINAL : public DataFile
{
public:
	NetDataFile(const QString& name, const QString& host, const StreamerManager& streamerManager = 0);
	~NetDataFile();

public:

private:
	QK_DECLARE_PRIVATE(NetDataFile)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::NetDataFile)

#endif // __QUANTKIT_NETDATAFILE_H__
