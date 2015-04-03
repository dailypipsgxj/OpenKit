#include <QuantKit/Streamer/DoubleStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class DoubleStreamerPrivate : public ObjectStreamerPrivate
{
public:
	DoubleStreamerPrivate();
	virtual ~DoubleStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE { return reader.ReadDouble(); }
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE { writer.Write((double)obj); }
	virtual DoubleStreamerPrivate* clone() Q_DECL_OVERRIDE { return new DoubleStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DoubleStreamerPrivate::DoubleStreamerPrivate()
{
		m_typeId = 158;
		m_type = typeof(double);
}

DoubleStreamerPrivate::~DoubleStreamerPrivate ()
{
}


// Pubic API 

DoubleStreamer::DoubleStreamer()
	: ObjectStreamer(*new DoubleStreamerPrivate)
{
}

DoubleStreamer::~DoubleStreamer()
{
}


