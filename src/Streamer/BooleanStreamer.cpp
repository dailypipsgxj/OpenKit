#include <QuantKit/Streamer/BooleanStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class BooleanStreamerPrivate : public ObjectStreamerPrivate
{
public:
	BooleanStreamerPrivate();
	virtual ~BooleanStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE { return reader.ReadBoolean(); }
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE { writer.Write((bool)obj); }
	virtual BooleanStreamerPrivate* clone() Q_DECL_OVERRIDE { return new BooleanStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

BooleanStreamerPrivate::BooleanStreamerPrivate()
{
		m_typeId = 155;
		m_type = typeof(bool);
}

BooleanStreamerPrivate::~BooleanStreamerPrivate ()
{
}


// Pubic API 

BooleanStreamer::BooleanStreamer()
	: ObjectStreamer(*new BooleanStreamerPrivate)
{
}

BooleanStreamer::~BooleanStreamer()
{
}


