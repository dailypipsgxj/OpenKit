#include <QuantKit/LicenseInfo.h>


namespace QuantKit {

class LicenseInfoPrivate : public QSharedData
{
public:
	LicenseInfoPrivate();
	virtual ~LicenseInfoPrivate();

public:
	bool licensed() const { return Class107.smethod_6(); }
	bool evaluationLockEnabled() const { return Class107.smethod_10(); }
	int evaluationTime() const { return Class107.smethod_20(); }
	int evaluationTimeCurrent() const { return Class107.smethod_22(); }
	bool expirationDateLockEnabled() const { return Class107.smethod_12(); }
	QDateTime expirationDate() const { return Class107.smethod_33(); }
	IDictionary<QString,QString> fields() const;
	virtual LicenseInfoPrivate* clone() Q_DECL_OVERRIDE { return new LicenseInfoPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

LicenseInfoPrivate::LicenseInfoPrivate()
{
}

LicenseInfoPrivate::~LicenseInfoPrivate ()
{
}

IDictionary<QString,QString> LicenseInfoPrivate::fields() const
{
	IDictionary<string, string> dictionary = new SortedDictionary<string, string>();
	foreach (DictionaryEntry dictionaryEntry in Class107.smethod_35())
	{
		string text = dictionaryEntry.Key.ToString();
		if (!text.StartsWith("#"))
		{
			dictionary.Add(text, dictionaryEntry.Value.ToString());
		}
	}
	return dictionary;
}


// Pubic API 

LicenseInfo::LicenseInfo()
	: d_ptr(new LicenseInfoPrivate)
{
}

LicenseInfo::~LicenseInfo()
{
}

LicenseInfo::LicenseInfo (const LicenseInfo &other)
	: d_ptr(other.d_ptr)
{
}

LicenseInfo& LicenseInfo::operator=(const LicenseInfo &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool LicenseInfo::operator==(const LicenseInfo &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

bool LicenseInfo::licensed() const
{
	return d_ptr->licensed();
}

bool LicenseInfo::evaluationLockEnabled() const
{
	return d_ptr->evaluationLockEnabled();
}

int LicenseInfo::evaluationTime() const
{
	return d_ptr->evaluationTime();
}

int LicenseInfo::evaluationTimeCurrent() const
{
	return d_ptr->evaluationTimeCurrent();
}

bool LicenseInfo::expirationDateLockEnabled() const
{
	return d_ptr->expirationDateLockEnabled();
}

QDateTime LicenseInfo::expirationDate() const
{
	return d_ptr->expirationDate();
}

IDictionary<QString,QString> LicenseInfo::fields() const
{
	return d_ptr->fields();
}

QDebug operator<<(QDebug dbg, const LicenseInfo& licenseinfo)
{
	return dbg << licenseinfo.toString();
}

