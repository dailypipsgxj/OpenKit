#include <QuantKit/StreamerPlugin.h>


namespace QuantKit {

class StreamerPluginPrivate : public QSharedData
{
public:
	QString m_typeName;

public:
	StreamerPluginPrivate();
	explicit StreamerPluginPrivate(const QString& typeName);
	virtual ~StreamerPluginPrivate();

public:
	QString typeName() const { return m_typeName; }
	void setTypeName(const QString& value) { m_typeName = value; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "StreamerPlugin"; }
	virtual StreamerPluginPrivate* clone() Q_DECL_OVERRIDE { return new StreamerPluginPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

StreamerPluginPrivate::StreamerPluginPrivate()
{
}

StreamerPluginPrivate::StreamerPluginPrivate(const QString& typeName)
	: m_typeName(typeName)
{
}

StreamerPluginPrivate::~StreamerPluginPrivate ()
{
}


// Pubic API 

StreamerPlugin::StreamerPlugin()
	: d_ptr(new StreamerPluginPrivate)
{
}

StreamerPlugin::StreamerPlugin(const QString& typeName)
	: d_ptr(new StreamerPluginPrivate(typeName))
{
}

StreamerPlugin::~StreamerPlugin()
{
}

StreamerPlugin::StreamerPlugin (const StreamerPlugin &other)
	: d_ptr(other.d_ptr)
{
}

StreamerPlugin& StreamerPlugin::operator=(const StreamerPlugin &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool StreamerPlugin::operator==(const StreamerPlugin &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString StreamerPlugin::typeName() const
{
	return d_ptr->typeName();
}

void StreamerPlugin::setTypeName(const QString& value)
{
	d_ptr->setTypeName(value);
}

QString StreamerPlugin::toString() const
{
	return d_ptr->toString();
}

QDebug operator<<(QDebug dbg, const StreamerPlugin& streamerplugin)
{
	return dbg << streamerplugin.toString();
}

