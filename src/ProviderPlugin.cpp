#include <QuantKit/ProviderPlugin.h>


namespace QuantKit {

class ProviderPluginPrivate : public QSharedData
{
public:
	QString m_typeName;
	bool m_x64;

public:
	ProviderPluginPrivate();
	ProviderPluginPrivate(const QString& typeName, bool x64);
	virtual ~ProviderPluginPrivate();

public:
	QString typeName() const { return m_typeName; }
	void setTypeName(const QString& value) { m_typeName = value; }
	bool x64() const { return m_x64; }
	void setX64(bool value) { m_x64 = value; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "ProviderPlugin"; }
	virtual ProviderPluginPrivate* clone() Q_DECL_OVERRIDE { return new ProviderPluginPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ProviderPluginPrivate::ProviderPluginPrivate()
{
}

ProviderPluginPrivate::ProviderPluginPrivate(const QString& typeName, bool x64)
	: m_typeName(typeName)
	, m_x64(x64)
{
}

ProviderPluginPrivate::~ProviderPluginPrivate ()
{
}


// Pubic API 

ProviderPlugin::ProviderPlugin()
	: d_ptr(new ProviderPluginPrivate)
{
}

ProviderPlugin::ProviderPlugin(const QString& typeName, bool x64)
	: d_ptr(new ProviderPluginPrivate(typeName, x64))
{
}

ProviderPlugin::~ProviderPlugin()
{
}

ProviderPlugin::ProviderPlugin (const ProviderPlugin &other)
	: d_ptr(other.d_ptr)
{
}

ProviderPlugin& ProviderPlugin::operator=(const ProviderPlugin &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ProviderPlugin::operator==(const ProviderPlugin &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString ProviderPlugin::typeName() const
{
	return d_ptr->typeName();
}

void ProviderPlugin::setTypeName(const QString& value)
{
	d_ptr->setTypeName(value);
}

bool ProviderPlugin::x64() const
{
	return d_ptr->x64();
}

void ProviderPlugin::setX64(bool value)
{
	d_ptr->setX64(value);
}

QString ProviderPlugin::toString() const
{
	return d_ptr->toString();
}

QDebug operator<<(QDebug dbg, const ProviderPlugin& providerplugin)
{
	return dbg << providerplugin.toString();
}

