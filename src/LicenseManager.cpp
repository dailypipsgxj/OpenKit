#include <QuantKit/LicenseManager.h>

#include <QuantKit/LicenseInfo.h>

namespace QuantKit {

class LicenseManagerPrivate : public QSharedData
{
public:
	LicenseManagerPrivate();
	virtual ~LicenseManagerPrivate();

public:
	QString getHardwareID()
	{
		return Class107.smethod_37(true, true, false, false);
	}

	LicenseInfo getLicense() { return new LicenseInfo(); }
	void loadLicense(const unsigned char& license) { Class107.smethod_3(license); }
	virtual LicenseManagerPrivate* clone() Q_DECL_OVERRIDE { return new LicenseManagerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

LicenseManagerPrivate::LicenseManagerPrivate()
{
}

LicenseManagerPrivate::~LicenseManagerPrivate ()
{
}


// Pubic API 

LicenseManager::LicenseManager()
	: d_ptr(new LicenseManagerPrivate)
{
}

LicenseManager::~LicenseManager()
{
}

LicenseManager::LicenseManager (const LicenseManager &other)
	: d_ptr(other.d_ptr)
{
}

LicenseManager& LicenseManager::operator=(const LicenseManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool LicenseManager::operator==(const LicenseManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString LicenseManager::getHardwareID()
{
	return d_ptr->getHardwareID();
}

LicenseInfo LicenseManager::getLicense()
{
	return d_ptr->getLicense();
}

void LicenseManager::loadLicense(unsigned char license)
{
	d_ptr->loadLicense(license);
}

QDebug operator<<(QDebug dbg, const LicenseManager& licensemanager)
{
	return dbg << licensemanager.toString();
}

