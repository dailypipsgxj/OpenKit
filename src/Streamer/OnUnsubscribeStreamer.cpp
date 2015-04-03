#include <QuantKit/Streamer/OnUnsubscribeStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class OnUnsubscribeStreamerPrivate : public ObjectStreamerPrivate
{
public:
	OnUnsubscribeStreamerPrivate();
	virtual ~OnUnsubscribeStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual OnUnsubscribeStreamerPrivate* clone() Q_DECL_OVERRIDE { return new OnUnsubscribeStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnUnsubscribeStreamerPrivate::OnUnsubscribeStreamerPrivate()
{
		m_typeId = 204;
		m_type = typeof(OnUnsubscribe);
}

OnUnsubscribeStreamerPrivate::~OnUnsubscribeStreamerPrivate ()
{
}

QVariant OnUnsubscribeStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	return new OnUnsubscribe
	{
		m_entryDate = new DateTime(reader.ReadInt64()),
		m_symbol = reader.ReadString()
	};
}

void OnUnsubscribeStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	OnUnsubscribe onUnsubscribe = (OnUnsubscribe)obj;
	writer.Write(onUnsubscribe.entryDate().Ticks);
	writer.Write(onUnsubscribe.symbol());
}


// Pubic API 

OnUnsubscribeStreamer::OnUnsubscribeStreamer()
	: ObjectStreamer(*new OnUnsubscribeStreamerPrivate)
{
}

OnUnsubscribeStreamer::~OnUnsubscribeStreamer()
{
}


