#ifndef __QUANTKIT_FILEDATASERVER_H__
#define __QUANTKIT_FILEDATASERVER_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QList>
#include <Dictionary>

#include <QuantKit/DataServer.h>
#include <QuantKit/BarType.h>
#include <QuantKit/SaveMode.h>

namespace QuantKit {

class FileDataServerPrivate;

class Framework;
class DataSeries;
class Instrument;
class Bar;
class DataObject;
class DataFile;
class IdArray;

class QUANTKIT_EXPORT FileDataServer Q_DECL_FINAL : public DataServer
{
public:
	FileDataServer(const Framework& framework, const QString& fileName, const QString& host = "", int port = -1);
	~FileDataServer();

public:

private:
	QK_DECLARE_PRIVATE(FileDataServer)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FileDataServer)

#endif // __QUANTKIT_FILEDATASERVER_H__
