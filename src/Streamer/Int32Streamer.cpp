#include <QuantKit/Streamer/Int32Streamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class Int32StreamerPrivate : public ObjectStreamerPrivate
{
public:
	Int32StreamerPrivate();
	virtual ~Int32StreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE { return reader.ReadInt32(); }
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE { writer.Write((int)obj); }
	virtual Int32StreamerPrivate* clone() Q_DECL_OVERRIDE { return new Int32StreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

Int32StreamerPrivate::Int32StreamerPrivate()
{
		m_typeId = 152;
		m_type = typeof(int);
}

Int32StreamerPrivate::~Int32StreamerPrivate ()
{
}


// Pubic API 

Int32Streamer::Int32Streamer()
	: ObjectStreamer(*new Int32StreamerPrivate)
{
}

Int32Streamer::~Int32Streamer()
{
}


