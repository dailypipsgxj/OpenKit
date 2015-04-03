#include <QuantKit/Streamer/Level2UpdateStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class Level2UpdateStreamerPrivate : public ObjectStreamerPrivate
{
public:
	Level2UpdateStreamerPrivate();
	virtual ~Level2UpdateStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual Level2UpdateStreamerPrivate* clone() Q_DECL_OVERRIDE { return new Level2UpdateStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

Level2UpdateStreamerPrivate::Level2UpdateStreamerPrivate()
{
		m_typeId = 9;
		m_type = typeof(Level2Update);
}

Level2UpdateStreamerPrivate::~Level2UpdateStreamerPrivate ()
{
}

QVariant Level2UpdateStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	Level2Update level2Update = new Level2Update();
	level2Update.setEntryDate() = DateTime.FromBinary(reader.ReadInt64());
	level2Update.setByte_0() = reader.ReadByte();
	level2Update.setInt_0() = reader.ReadInt32();
	int num = reader.ReadInt32();
	level2Update.setEntries() = new Level2[num];
	for (int i = 0; i < num; i++)
	{
		level2Update.entries()[i] = (Level2)m_streamerManager.Deserialize(reader);
	}
	return level2Update;
}

void Level2UpdateStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Level2Update level2Update = (Level2Update)obj;
	writer.Write(level2Update.entryDate().ToBinary());
	writer.Write(level2Update.byte_0());
	writer.Write(level2Update.int_0());
	writer.Write(level2Update.entries().Length);
	Level2[] entries = level2Update.entries();
	for (int i = 0; i < entries.Length; i++)
	{
		Level2 obj2 = entries[i];
		m_streamerManager.Serialize(writer, obj2);
	}
}


// Pubic API 

Level2UpdateStreamer::Level2UpdateStreamer()
	: ObjectStreamer(*new Level2UpdateStreamerPrivate)
{
}

Level2UpdateStreamer::~Level2UpdateStreamer()
{
}


