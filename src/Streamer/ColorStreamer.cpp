#include <QuantKit/Streamer/ColorStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class ColorStreamerPrivate : public ObjectStreamerPrivate
{
public:
	ColorStreamerPrivate();
	virtual ~ColorStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE
	{
		return Color.FromArgb(reader.ReadInt32());
	}

	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE
	{
		writer.Write(((Color)obj).ToArgb());
	}

	virtual ColorStreamerPrivate* clone() Q_DECL_OVERRIDE { return new ColorStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ColorStreamerPrivate::ColorStreamerPrivate()
{
		m_typeId = 156;
		m_type = typeof(Color);
}

ColorStreamerPrivate::~ColorStreamerPrivate ()
{
}


// Pubic API 

ColorStreamer::ColorStreamer()
	: ObjectStreamer(*new ColorStreamerPrivate)
{
}

ColorStreamer::~ColorStreamer()
{
}


