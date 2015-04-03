#include <QuantKit/NetDataFile.h>

#include <QuantKit/StreamerManager.h>
#include "DataFile_p.h"

namespace QuantKit {

class NetDataFilePrivate : public DataFilePrivate
{
public:
	QString string_2;
	int OydsObdvpm;
	TcpClient tcpClient_0;

public:
	NetDataFilePrivate(const QString& name, const QString& host, const StreamerManager& streamerManager);
	virtual ~NetDataFilePrivate();

public:
	virtual void flush() Q_DECL_OVERRIDE;
	virtual void open(FileMode mode) Q_DECL_OVERRIDE;
	virtual NetDataFilePrivate* clone() Q_DECL_OVERRIDE { return new NetDataFilePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

NetDataFilePrivate::NetDataFilePrivate(const QString& name, const QString& host, StreamerManager streamerManager)
	: DataFilePrivate (name, streamerManager)
	, string_2(host)
	, OydsObdvpm(1000)
{
}

NetDataFilePrivate::~NetDataFilePrivate ()
{
}

void NetDataFilePrivate::flush()
{
	if (bool_1)
	{
		base.Flush();
		stream_0.WriteByte(2);
	}
}

void NetDataFilePrivate::open(FileMode mode)
{
	if (bool_0)
	{
		Console.WriteLine("DataFile::Open File is already open: " + string_1);
		return;
	}
	if (!OpenFileStream(string_1, mode))
	{
		long_0 = 62L;
		long_1 = 62L;
		aCdHfUdLo6 = 62L;
		long_2 = 62L;
		int_0 = 0;
		int_1 = 0;
		int_2 = 0;
		int_3 = 0;
		bool_1 = true;
		base.method_0();
	}
	else
	{
		if (!base.lEqHupgyQs())
		{
			Console.WriteLine("DataFile::Open Error opening file " + string_1);
			return;
		}
		base.ReadKeys();
		base.ReadFree();
	}
	bool_0 = true;
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(NetDataFile)

NetDataFile::NetDataFile(const QString& name, const QString& host, StreamerManager streamerManager)
	: DataFile(*new NetDataFilePrivate(name, host, streamerManager))
{
}

NetDataFile::~NetDataFile()
{
}


