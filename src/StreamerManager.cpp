#include <QuantKit/StreamerManager.h>

#include "ObjectStreamer_p.h"
#include "Event_p.h"
#include "DataObject_p.h"
#include <QuantKit/IdArray.h>

namespace QuantKit {

class StreamerManagerPrivate : public QSharedData
{
public:
	IdArray<ObjectStreamer> m_idArray;
	Dictionary<Type,ObjectStreamer> m_dictionary;

public:
	StreamerManagerPrivate();
	virtual ~StreamerManagerPrivate();

public:
	IdArray<ObjectStreamer> getIdArray() const;

	Dictionary<Type,ObjectStreamer> getDictionary() const;
	void add(const ObjectStreamer& streamer);
	QVariant deserialize(const QByteArray& reader);
	bool hasStreamer(const QVariant& obj)
	{
		return HasStreamer(obj.GetType());
	}

	bool hasStreamer(const Type& type)
	{
		return m_dictionary.ContainsKey(type);
	}

	bool hasStreamer(int typeId)
	{
		return m_idArray[typeId] != null;
	}

	void remove(const ObjectStreamer& streamer);
	void remove(unsigned char typeId);
	void remove(const Type& type);
	void serialize(const QByteArray& writer, const QVariant& obj);
	void serialize(const QByteArray& writer, const Event& e);
	void serialize(const QByteArray& writer, const DataObject& obj);
	virtual StreamerManagerPrivate* clone() Q_DECL_OVERRIDE { return new StreamerManagerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

StreamerManagerPrivate::StreamerManagerPrivate()
	: m_idArray(new IdArray<ObjectStreamer>(1000))
	, m_dictionary(new Dictionary<Type, ObjectStreamer>())
{
		Add(new FreeKeyListStreamer());
		Add(new ObjectKeyListStreamer());
		Add(new DataSeriesStreamer());
		Add(new DataKeyIdArrayStreamer());
}

StreamerManagerPrivate::~StreamerManagerPrivate ()
{
}

IdArray<ObjectStreamer> getIdArray() const
{
	return null;
}

Dictionary<Type,ObjectStreamer> getDictionary() const
{
	return null;
}
void StreamerManagerPrivate::add(const ObjectStreamer& streamer)
{
	ObjectStreamer objectStreamer = m_idArray[(int)streamer.typeId()];
	if (objectStreamer != null && objectStreamer.type() != streamer.type())
	{
		throw new Exception(string.Concat(new object[]
		{
			"StreamerManager::Add Streamer with the same typeId but different type is already registered in the StreamerManager ",
			objectStreamer.typeId(),
			" ",
			objectStreamer.type()
		}));
	}
	streamer.setStreamerManager() = this;
	m_idArray[(int)streamer.typeId()] = streamer;
	m_dictionary[streamer.type()] = streamer;
}

QVariant StreamerManagerPrivate::deserialize(const QByteArray& reader)
{
	int id = (int)reader.ReadByte();
	byte version = reader.ReadByte();
	ObjectStreamer objectStreamer = m_idArray[id];
	return objectStreamer.Read(reader, version);
}

void StreamerManagerPrivate::remove(const ObjectStreamer& streamer)
{
	m_idArray.Remove((int)streamer.typeId());
	m_dictionary.Remove(streamer.type());
}

void StreamerManagerPrivate::remove(unsigned char typeId)
{
	ObjectStreamer objectStreamer = m_idArray[(int)typeId];
	if (objectStreamer != null)
	{
		Remove(objectStreamer);
	}
}

void StreamerManagerPrivate::remove(const Type& type)
{
	ObjectStreamer objectStreamer = m_dictionary[type];
	if (objectStreamer != null)
	{
		Remove(objectStreamer);
	}
}

void StreamerManagerPrivate::serialize(const QByteArray& writer, const QVariant& obj)
{
	Type type = obj.GetType();
	ObjectStreamer objectStreamer = m_dictionary[type];
	writer.Write(objectStreamer.typeId());
	writer.Write(objectStreamer.GetVersion(obj));
	objectStreamer.Write(writer, obj);
}

void StreamerManagerPrivate::serialize(const QByteArray& writer, const Event& e)
{
	ObjectStreamer objectStreamer = m_idArray[(int)e.typeId()];
	writer.Write(objectStreamer.typeId());
	writer.Write(objectStreamer.GetVersion(e));
	objectStreamer.Write(writer, e);
}

void StreamerManagerPrivate::serialize(const QByteArray& writer, const DataObject& obj)
{
	ObjectStreamer objectStreamer = m_idArray[(int)obj.typeId()];
	writer.Write(objectStreamer.typeId());
	writer.Write(objectStreamer.GetVersion(obj));
	objectStreamer.Write(writer, obj);
}


// Pubic API 

StreamerManager::StreamerManager()
	: d_ptr(new StreamerManagerPrivate)
{
}

StreamerManager::~StreamerManager()
{
}

StreamerManager::StreamerManager (const StreamerManager &other)
	: d_ptr(other.d_ptr)
{
}

StreamerManager& StreamerManager::operator=(const StreamerManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool StreamerManager::operator==(const StreamerManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IdArray<ObjectStreamer> idArray() const
{
	return d_ptr->
	setIdArray()
}

Dictionary<Type,ObjectStreamer> dictionary() const
{
	return d_ptr->
	setDictionary()
}

void StreamerManager::add(const ObjectStreamer& streamer)
{
	d_ptr->add(streamer);
}

QVariant StreamerManager::deserialize(const QByteArray& reader)
{
	return d_ptr->deserialize(reader);
}

bool StreamerManager::hasStreamer(const QVariant& obj)
{
	return d_ptr->hasStreamer(obj);
}

bool StreamerManager::hasStreamer(const Type& type)
{
	return d_ptr->hasStreamer(type);
}

bool StreamerManager::hasStreamer(int typeId)
{
	return d_ptr->hasStreamer(typeId);
}

void StreamerManager::remove(const ObjectStreamer& streamer)
{
	d_ptr->remove(streamer);
}

void StreamerManager::remove(unsigned char typeId)
{
	d_ptr->remove(typeId);
}

void StreamerManager::remove(const Type& type)
{
	d_ptr->remove(type);
}

void StreamerManager::serialize(const QByteArray& writer, const QVariant& obj)
{
	d_ptr->serialize(writer, obj);
}

void StreamerManager::serialize(const QByteArray& writer, const Event& e)
{
	d_ptr->serialize(writer, e);
}

void StreamerManager::serialize(const QByteArray& writer, const DataObject& obj)
{
	d_ptr->serialize(writer, obj);
}

QDebug operator<<(QDebug dbg, const StreamerManager& streamermanager)
{
	return dbg << streamermanager.toString();
}

