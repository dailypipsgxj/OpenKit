#include <QuantKit/Streamer/QuoteStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class QuoteStreamerPrivate : public ObjectStreamerPrivate
{
public:
	QuoteStreamerPrivate();
	virtual ~QuoteStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE
	{
		return new Quote(new DateTime(reader.ReadInt64()), reader.ReadByte(), reader.ReadInt32(), reader.ReadDouble(), reader.ReadInt32(), reader.ReadDouble(), reader.ReadInt32());
	}

	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual QuoteStreamerPrivate* clone() Q_DECL_OVERRIDE { return new QuoteStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

QuoteStreamerPrivate::QuoteStreamerPrivate()
{
		m_typeId = 5;
		m_type = typeof(Quote);
}

QuoteStreamerPrivate::~QuoteStreamerPrivate ()
{
}

void QuoteStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Quote quote = (Quote)obj;
	writer.Write(quote.dateTime().Ticks);
	writer.Write(quote.bid().providerId());
	writer.Write(quote.bid().instrumentId());
	writer.Write(quote.bid().price());
	writer.Write(quote.bid().size());
	writer.Write(quote.ask().price());
	writer.Write(quote.ask().size());
}


// Pubic API 

QuoteStreamer::QuoteStreamer()
	: ObjectStreamer(*new QuoteStreamerPrivate)
{
}

QuoteStreamer::~QuoteStreamer()
{
}


