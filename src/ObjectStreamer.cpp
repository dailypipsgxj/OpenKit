#include <QuantKit/ObjectStreamer.h>

#include <QuantKit/StreamerManager.h>
#include "ObjectStreamer_p.h"

using namespace QuantKit;

ObjectStreamerPrivate::ObjectStreamerPrivate()
	: m_type(typeof(object))
{
}

ObjectStreamerPrivate::~ObjectStreamerPrivate ()
{
}

unsigned char getTypeId() const
{
	return 0;
}
void setTypeId(unsigned char value)
{
}

Type getType() const
{
	return null;
}
void setType(Type value)
{
}

unsigned char getVersion() const
{
	return 0;
}
void setVersion(unsigned char value)
{
}
void ObjectStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
}


// Pubic API 

ObjectStreamer::ObjectStreamer()
	: d_ptr(new ObjectStreamerPrivate)
{
}

ObjectStreamer::~ObjectStreamer()
{
}

ObjectStreamer::ObjectStreamer (ObjectStreamerPrivate &dd)
	: d_ptr(&dd)
{
}

ObjectStreamer::ObjectStreamer (const ObjectStreamer &other)
	: d_ptr(other.d_ptr)
{
}

ObjectStreamer& ObjectStreamer::operator=(const ObjectStreamer &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ObjectStreamer::operator==(const ObjectStreamer &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

unsigned char typeId() const
{
	return d_ptr->
	setTypeId()
}

void setTypeId(unsigned char value)
{
	d_ptr->typeId(value);
}

Type type() const
{
	return d_ptr->
	setType()
}

void setType(Type value)
{
	d_ptr->type(value);
}

unsigned char version() const
{
	return d_ptr->
	setVersion()
}

void setVersion(unsigned char value)
{
	d_ptr->version(value);
}

StreamerManager ObjectStreamer::streamerManager() const
{
	return d_ptr->streamerManager();
}

unsigned char ObjectStreamer::getVersion(const QVariant& obj)
{
	return d_ptr->getVersion(obj);
}

QVariant ObjectStreamer::read(const QByteArray& reader, unsigned char version)
{
	return d_ptr->read(reader, version);
}

void ObjectStreamer::write(const QByteArray& writer, const QVariant& obj)
{
	d_ptr->write(writer, obj);
}

QDebug operator<<(QDebug dbg, const ObjectStreamer& objectstreamer)
{
	return dbg << objectstreamer.toString();
}

