#include <QuantKit/Streamer/GroupStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class GroupStreamerPrivate : public ObjectStreamerPrivate
{
public:
	GroupStreamerPrivate();
	virtual ~GroupStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual GroupStreamerPrivate* clone() Q_DECL_OVERRIDE { return new GroupStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

GroupStreamerPrivate::GroupStreamerPrivate()
{
		m_typeId = 50;
		m_type = typeof(Group);
}

GroupStreamerPrivate::~GroupStreamerPrivate ()
{
}

QVariant GroupStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	string name = reader.ReadString();
	int id = reader.ReadInt32();
	Group group = new Group(name);
	group.setId() = id;
	int num = reader.ReadInt32();
	for (int i = 0; i < num; i++)
	{
		string name2 = reader.ReadString();
		byte type = reader.ReadByte();
		object value = m_streamerManager.Deserialize(reader);
		group.Add(name2, type, value);
	}
	return group;
}

void GroupStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Group group = obj as Group;
	writer.Write(group.name());
	writer.Write(group.id());
	writer.Write(group.fields().Count);
	foreach (GroupField current in group.fields().Values)
	{
		writer.Write(current.name());
		writer.Write(current.type());
		m_streamerManager.Serialize(writer, current.value());
	}
}


// Pubic API 

GroupStreamer::GroupStreamer()
	: ObjectStreamer(*new GroupStreamerPrivate)
{
}

GroupStreamer::~GroupStreamer()
{
}


