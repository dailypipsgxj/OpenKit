#include <QuantKit/Streamer/Int16Streamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class Int16StreamerPrivate : public ObjectStreamerPrivate
{
public:
	Int16StreamerPrivate();
	virtual ~Int16StreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE { return reader.ReadInt16(); }
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE { writer.Write((short)obj); }
	virtual Int16StreamerPrivate* clone() Q_DECL_OVERRIDE { return new Int16StreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

Int16StreamerPrivate::Int16StreamerPrivate()
{
		m_typeId = 159;
		m_type = typeof(short);
}

Int16StreamerPrivate::~Int16StreamerPrivate ()
{
}


// Pubic API 

Int16Streamer::Int16Streamer()
	: ObjectStreamer(*new Int16StreamerPrivate)
{
}

Int16Streamer::~Int16Streamer()
{
}


