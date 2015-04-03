#include <QuantKit/ServerConfiguration.h>


namespace QuantKit {

class ServerConfigurationPrivate : public QSharedData
{
public:
	QString TypeName;
	QString ConnectionString;

public:
	ServerConfigurationPrivate();
	virtual ~ServerConfigurationPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

ServerConfigurationPrivate::ServerConfigurationPrivate()
{
}

ServerConfigurationPrivate::~ServerConfigurationPrivate ()
{
}


// Pubic API 

ServerConfiguration::ServerConfiguration()
	: d_ptr(new ServerConfigurationPrivate)
{
}

ServerConfiguration::~ServerConfiguration()
{
}

ServerConfiguration::ServerConfiguration (const ServerConfiguration &other)
	: d_ptr(other.d_ptr)
{
}

ServerConfiguration& ServerConfiguration::operator=(const ServerConfiguration &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ServerConfiguration::operator==(const ServerConfiguration &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const ServerConfiguration& serverconfiguration)
{
	return dbg << serverconfiguration.toString();
}

