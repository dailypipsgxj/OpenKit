#include <QuantKit/Streamer/GroupUpdateStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class GroupUpdateStreamerPrivate : public ObjectStreamerPrivate
{
public:
	GroupUpdateStreamerPrivate();
	virtual ~GroupUpdateStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual GroupUpdateStreamerPrivate* clone() Q_DECL_OVERRIDE { return new GroupUpdateStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

GroupUpdateStreamerPrivate::GroupUpdateStreamerPrivate()
{
		m_typeId = 51;
		m_type = typeof(GroupUpdate);
}

GroupUpdateStreamerPrivate::~GroupUpdateStreamerPrivate ()
{
}

QVariant GroupUpdateStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	reader.ReadInt32();
	m_streamerManager.Deserialize(reader);
	return null;
}

void GroupUpdateStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	GroupEvent groupEvent = obj as GroupEvent;
	m_streamerManager.Serialize(writer, groupEvent.obj());
}


// Pubic API 

GroupUpdateStreamer::GroupUpdateStreamer()
	: ObjectStreamer(*new GroupUpdateStreamerPrivate)
{
}

GroupUpdateStreamer::~GroupUpdateStreamer()
{
}


