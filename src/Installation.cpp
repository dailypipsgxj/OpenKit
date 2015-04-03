#include <QuantKit/Installation.h>


namespace QuantKit {

class InstallationPrivate : public QSharedData
{
public:
	virtual ~InstallationPrivate();

public:
	DirectoryInfo applicationDir() const
	{
		return new DirectoryInfo(Environment.CurrentDirectory);
	}

	DirectoryInfo dataDir() const
	{
		return new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\SmartQuant Ltd\\OpenQuant 2014\\data");
	}

	DirectoryInfo configDir() const
	{
		return new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\SmartQuant Ltd\\OpenQuant 2014\\config");
	}

	virtual InstallationPrivate* clone() Q_DECL_OVERRIDE { return new InstallationPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

InstallationPrivate::~InstallationPrivate ()
{
}


// Pubic API 

Installation::~Installation()
{
}

Installation::Installation (const Installation &other)
	: d_ptr(other.d_ptr)
{
}

Installation& Installation::operator=(const Installation &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Installation::operator==(const Installation &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

DirectoryInfo Installation::applicationDir() const
{
	return d_ptr->applicationDir();
}

DirectoryInfo Installation::dataDir() const
{
	return d_ptr->dataDir();
}

DirectoryInfo Installation::configDir() const
{
	return d_ptr->configDir();
}

QDebug operator<<(QDebug dbg, const Installation& installation)
{
	return dbg << installation.toString();
}

