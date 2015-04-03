#include <QuantKit/Streamer/ByteStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class ByteStreamerPrivate : public ObjectStreamerPrivate
{
public:
	ByteStreamerPrivate();
	virtual ~ByteStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE { return reader.ReadByte(); }
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE { writer.Write((byte)obj); }
	virtual ByteStreamerPrivate* clone() Q_DECL_OVERRIDE { return new ByteStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ByteStreamerPrivate::ByteStreamerPrivate()
{
		m_typeId = 157;
		m_type = typeof(byte);
}

ByteStreamerPrivate::~ByteStreamerPrivate ()
{
}


// Pubic API 

ByteStreamer::ByteStreamer()
	: ObjectStreamer(*new ByteStreamerPrivate)
{
}

ByteStreamer::~ByteStreamer()
{
}


