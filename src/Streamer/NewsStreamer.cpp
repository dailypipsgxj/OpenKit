#include <QuantKit/Streamer/NewsStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class NewsStreamerPrivate : public ObjectStreamerPrivate
{
public:
	NewsStreamerPrivate();
	virtual ~NewsStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual NewsStreamerPrivate* clone() Q_DECL_OVERRIDE { return new NewsStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

NewsStreamerPrivate::NewsStreamerPrivate()
{
		m_typeId = 23;
		m_type = typeof(News);
}

NewsStreamerPrivate::~NewsStreamerPrivate ()
{
}

QVariant NewsStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	return new News
	{
		m_entryDate = new DateTime(reader.ReadInt64()),
		int_0 = reader.ReadInt32(),
		int_1 = reader.ReadInt32(),
		byte_0 = reader.ReadByte(),
		string_0 = reader.ReadString(),
		string_1 = reader.ReadString(),
		string_2 = reader.ReadString()
	};
}

void NewsStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	News news = obj as News;
	writer.Write(news.entryDate().Ticks);
	writer.Write(news.int_0());
	writer.Write(news.int_1());
	writer.Write(news.byte_0());
	writer.Write(news.string_0());
	writer.Write(news.string_1());
	writer.Write(news.string_2());
}


// Pubic API 

NewsStreamer::NewsStreamer()
	: ObjectStreamer(*new NewsStreamerPrivate)
{
}

NewsStreamer::~NewsStreamer()
{
}


