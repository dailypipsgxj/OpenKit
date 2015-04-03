#include <QuantKit/Streamer/FundamentalStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class FundamentalStreamerPrivate : public ObjectStreamerPrivate
{
public:
	FundamentalStreamerPrivate();
	virtual ~FundamentalStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual FundamentalStreamerPrivate* clone() Q_DECL_OVERRIDE { return new FundamentalStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

FundamentalStreamerPrivate::FundamentalStreamerPrivate()
{
		m_typeId = 22;
		m_type = typeof(Fundamental);
}

FundamentalStreamerPrivate::~FundamentalStreamerPrivate ()
{
}

QVariant FundamentalStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	return new Fundamental
	{
		m_entryDate = new DateTime(reader.ReadInt64()),
		int_0 = reader.ReadInt32(),
		int_1 = reader.ReadInt32(),
		m_item = (ObjectTable)m_streamerManager.Deserialize(reader)
	};
}

void FundamentalStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Fundamental fundamental = (Fundamental)obj;
	writer.Write(fundamental.entryDate().Ticks);
	writer.Write(fundamental.int_0());
	writer.Write(fundamental.int_1());
	m_streamerManager.Serialize(writer, fundamental.item());
}


// Pubic API 

FundamentalStreamer::FundamentalStreamer()
	: ObjectStreamer(*new FundamentalStreamerPrivate)
{
}

FundamentalStreamer::~FundamentalStreamer()
{
}


