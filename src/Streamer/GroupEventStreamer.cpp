#include <QuantKit/Streamer/GroupEventStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class GroupEventStreamerPrivate : public ObjectStreamerPrivate
{
public:
	GroupEventStreamerPrivate();
	virtual ~GroupEventStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual GroupEventStreamerPrivate* clone() Q_DECL_OVERRIDE { return new GroupEventStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

GroupEventStreamerPrivate::GroupEventStreamerPrivate()
{
		m_typeId = 52;
		m_type = typeof(GroupEvent);
}

GroupEventStreamerPrivate::~GroupEventStreamerPrivate ()
{
}

QVariant GroupEventStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	int groupId = reader.ReadInt32();
	Event obj = m_streamerManager.Deserialize(reader) as Event;
	return new GroupEvent(obj, groupId);
}

void GroupEventStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	GroupEvent groupEvent = obj as GroupEvent;
	writer.Write((groupEvent.group() == null) ? groupEvent.groupId() : groupEvent.group().id());
	m_streamerManager.Serialize(writer, groupEvent.obj());
}


// Pubic API 

GroupEventStreamer::GroupEventStreamer()
	: ObjectStreamer(*new GroupEventStreamerPrivate)
{
}

GroupEventStreamer::~GroupEventStreamer()
{
}


