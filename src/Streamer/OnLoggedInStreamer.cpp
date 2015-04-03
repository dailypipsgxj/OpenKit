#include <QuantKit/Streamer/OnLoggedInStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class OnLoggedInStreamerPrivate : public ObjectStreamerPrivate
{
public:
	OnLoggedInStreamerPrivate();
	virtual ~OnLoggedInStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE
	{
		writer.Write((obj as Event).entryDate().Ticks);
	}

	virtual OnLoggedInStreamerPrivate* clone() Q_DECL_OVERRIDE { return new OnLoggedInStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnLoggedInStreamerPrivate::OnLoggedInStreamerPrivate()
{
		m_typeId = 217;
		m_type = typeof(OnLoggedIn);
}

OnLoggedInStreamerPrivate::~OnLoggedInStreamerPrivate ()
{
}

QVariant OnLoggedInStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	DateTime dateTime = new DateTime(reader.ReadInt64());
	return new OnLoggedIn(dateTime);
}


// Pubic API 

OnLoggedInStreamer::OnLoggedInStreamer()
	: ObjectStreamer(*new OnLoggedInStreamerPrivate)
{
}

OnLoggedInStreamer::~OnLoggedInStreamer()
{
}


