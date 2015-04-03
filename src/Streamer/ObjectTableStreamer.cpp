#include <QuantKit/Streamer/ObjectTableStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class ObjectTableStreamerPrivate : public ObjectStreamerPrivate
{
public:
	ObjectTableStreamerPrivate();
	virtual ~ObjectTableStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual ObjectTableStreamerPrivate* clone() Q_DECL_OVERRIDE { return new ObjectTableStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ObjectTableStreamerPrivate::ObjectTableStreamerPrivate()
{
		m_typeId = 24;
		m_type = typeof(ObjectTable);
}

ObjectTableStreamerPrivate::~ObjectTableStreamerPrivate ()
{
}

QVariant ObjectTableStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	ObjectTable objectTable = new ObjectTable();
	int id;
	while ((id = reader.ReadInt32()) != -1)
	{
		objectTable.item()[id] = m_streamerManager.Deserialize(reader);
	}
	return objectTable;
}

void ObjectTableStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	ObjectTable objectTable = (ObjectTable)obj;
	for (int i = 0; i < objectTable.item().Size; i++)
	{
		if (objectTable.item()[i] != null)
		{
			writer.Write(i);
			m_streamerManager.Serialize(writer, objectTable.item()[i]);
		}
	}
	writer.Write(-1);
}


// Pubic API 

ObjectTableStreamer::ObjectTableStreamer()
	: ObjectStreamer(*new ObjectTableStreamerPrivate)
{
}

ObjectTableStreamer::~ObjectTableStreamer()
{
}


