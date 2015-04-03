#include <QuantKit/Streamer/TextInfoStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class TextInfoStreamerPrivate : public ObjectStreamerPrivate
{
public:
	TextInfoStreamerPrivate();
	virtual ~TextInfoStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual TextInfoStreamerPrivate* clone() Q_DECL_OVERRIDE { return new TextInfoStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TextInfoStreamerPrivate::TextInfoStreamerPrivate()
{
		m_typeId = 17;
		m_type = typeof(TextInfo);
}

TextInfoStreamerPrivate::~TextInfoStreamerPrivate ()
{
}

QVariant TextInfoStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	DateTime dateTime = new DateTime(reader.ReadInt64());
	string content = reader.ReadString();
	return new TextInfo(dateTime, content);
}

void TextInfoStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	TextInfo textInfo = obj as TextInfo;
	writer.Write(textInfo.dateTime().Ticks);
	writer.Write(textInfo.content());
}


// Pubic API 

TextInfoStreamer::TextInfoStreamer()
	: ObjectStreamer(*new TextInfoStreamerPrivate)
{
}

TextInfoStreamer::~TextInfoStreamer()
{
}


