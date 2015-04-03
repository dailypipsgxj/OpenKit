#include <QuantKit/DataFileServer.h>

#include <QuantKit/DataFileManager.h>

namespace QuantKit {

class DataFileServerPrivate : public QSharedData
{
public:
	int int_0;
	IPAddress ipaddress_0;
	TcpListener tcpListener_0;
	DataFileManager dataFileManager_0;

public:
	DataFileServerPrivate(int port, const QString& path)
	{
		Console.WriteLine(DateTime.Now + " Creating DataFileServer on path " + path);
	}

	virtual ~DataFileServerPrivate();

public:
	void start();
	void stop();
	virtual DataFileServerPrivate* clone() Q_DECL_OVERRIDE { return new DataFileServerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DataFileServerPrivate::~DataFileServerPrivate ()
{
}

void DataFileServerPrivate::start()
{
	tcpListener_0 = new TcpListener(ipaddress_0, int_0);
	tcpListener_0.Start();
	while (true)
	{
		Console.WriteLine(string.Concat(new object[]
		{
			DateTime.Now,
			" Listening for client connection on port ",
			int_0,
			" ..."
		}));
		TcpClient client = tcpListener_0.AcceptTcpClient();
		Console.WriteLine(DateTime.Now + " Client connected");
		new DataFileServerClient_(client, dataFileManager_0);
	}
}

void DataFileServerPrivate::stop()
{
	tcpListener_0.Stop();
	dataFileManager_0.Close();
}


// Pubic API 

DataFileServer::DataFileServer(int port, const QString& path)
	: d_ptr(new DataFileServerPrivate(port, path))
{
}

DataFileServer::~DataFileServer()
{
}

DataFileServer::DataFileServer (const DataFileServer &other)
	: d_ptr(other.d_ptr)
{
}

DataFileServer& DataFileServer::operator=(const DataFileServer &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataFileServer::operator==(const DataFileServer &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void DataFileServer::start()
{
	d_ptr->start();
}

void DataFileServer::stop()
{
	d_ptr->stop();
}

QDebug operator<<(QDebug dbg, const DataFileServer& datafileserver)
{
	return dbg << datafileserver.toString();
}

