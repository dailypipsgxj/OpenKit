#ifndef __QUANTKIT_FILEINSTRUMENTSERVER_H__
#define __QUANTKIT_FILEINSTRUMENTSERVER_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/InstrumentServer.h>

namespace QuantKit {

class FileInstrumentServerPrivate;

class Framework;
class InstrumentList;
class Instrument;
class DataFile;

class QUANTKIT_EXPORT FileInstrumentServer Q_DECL_FINAL : public InstrumentServer
{
public:
	FileInstrumentServer(const Framework& framework, const QString& fileName, const QString& host = "", int port = -1);
	~FileInstrumentServer();

public:

private:
	QK_DECLARE_PRIVATE(FileInstrumentServer)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FileInstrumentServer)

#endif // __QUANTKIT_FILEINSTRUMENTSERVER_H__
