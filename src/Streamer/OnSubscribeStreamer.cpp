#include <QuantKit/Streamer/OnSubscribeStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class OnSubscribeStreamerPrivate : public ObjectStreamerPrivate
{
public:
	OnSubscribeStreamerPrivate();
	virtual ~OnSubscribeStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual OnSubscribeStreamerPrivate* clone() Q_DECL_OVERRIDE { return new OnSubscribeStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnSubscribeStreamerPrivate::OnSubscribeStreamerPrivate()
{
		m_typeId = 203;
		m_type = typeof(OnSubscribe);
}

OnSubscribeStreamerPrivate::~OnSubscribeStreamerPrivate ()
{
}

QVariant OnSubscribeStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	return new OnSubscribe
	{
		m_entryDate = new DateTime(reader.ReadInt64()),
		m_symbol = reader.ReadString()
	};
}

void OnSubscribeStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	OnSubscribe onSubscribe = (OnSubscribe)obj;
	writer.Write(onSubscribe.entryDate().Ticks);
	writer.Write(onSubscribe.symbol());
}


// Pubic API 

OnSubscribeStreamer::OnSubscribeStreamer()
	: ObjectStreamer(*new OnSubscribeStreamerPrivate)
{
}

OnSubscribeStreamer::~OnSubscribeStreamer()
{
}


