#include <QuantKit/Streamer/CharStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class CharStreamerPrivate : public ObjectStreamerPrivate
{
public:
	CharStreamerPrivate();
	virtual ~CharStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE { return reader.ReadChar(); }
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE { writer.Write((char)obj); }
	virtual CharStreamerPrivate* clone() Q_DECL_OVERRIDE { return new CharStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

CharStreamerPrivate::CharStreamerPrivate()
{
		m_typeId = 154;
		m_type = typeof(char);
}

CharStreamerPrivate::~CharStreamerPrivate ()
{
}


// Pubic API 

CharStreamer::CharStreamer()
	: ObjectStreamer(*new CharStreamerPrivate)
{
}

CharStreamer::~CharStreamer()
{
}


