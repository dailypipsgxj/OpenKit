#include <QuantKit/Streamer/Int64Streamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class Int64StreamerPrivate : public ObjectStreamerPrivate
{
public:
	Int64StreamerPrivate();
	virtual ~Int64StreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE { return reader.ReadInt64(); }
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE { writer.Write((long)obj); }
	virtual Int64StreamerPrivate* clone() Q_DECL_OVERRIDE { return new Int64StreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

Int64StreamerPrivate::Int64StreamerPrivate()
{
		m_typeId = 151;
		m_type = typeof(long);
}

Int64StreamerPrivate::~Int64StreamerPrivate ()
{
}


// Pubic API 

Int64Streamer::Int64Streamer()
	: ObjectStreamer(*new Int64StreamerPrivate)
{
}

Int64Streamer::~Int64Streamer()
{
}


