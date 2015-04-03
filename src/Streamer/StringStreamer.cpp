#include <QuantKit/Streamer/StringStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class StringStreamerPrivate : public ObjectStreamerPrivate
{
public:
	StringStreamerPrivate();
	virtual ~StringStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE { return reader.ReadString(); }
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE { writer.Write((string)obj); }
	virtual StringStreamerPrivate* clone() Q_DECL_OVERRIDE { return new StringStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

StringStreamerPrivate::StringStreamerPrivate()
{
		m_typeId = 150;
		m_type = typeof(string);
}

StringStreamerPrivate::~StringStreamerPrivate ()
{
}


// Pubic API 

StringStreamer::StringStreamer()
	: ObjectStreamer(*new StringStreamerPrivate)
{
}

StringStreamer::~StringStreamer()
{
}


