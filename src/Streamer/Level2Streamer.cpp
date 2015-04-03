#include <QuantKit/Streamer/Level2Streamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class Level2StreamerPrivate : public ObjectStreamerPrivate
{
public:
	Level2StreamerPrivate();
	virtual ~Level2StreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual Level2StreamerPrivate* clone() Q_DECL_OVERRIDE { return new Level2StreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

Level2StreamerPrivate::Level2StreamerPrivate()
{
		m_typeId = 7;
		m_type = typeof(Level2);
}

Level2StreamerPrivate::~Level2StreamerPrivate ()
{
}

QVariant Level2StreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	return new Level2
	{
		m_entryDate = DateTime.FromBinary(reader.ReadInt64()),
		m_providerId = reader.ReadByte(),
		m_instrumentId = reader.ReadInt32(),
		m_price = reader.ReadDouble(),
		m_size = reader.ReadInt32(),
		m_side = (Level2Side)reader.ReadByte(),
		m_action = (GEnum0)reader.ReadByte(),
		m_position = reader.ReadInt32()
	};
}

void Level2StreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Level2 level = (Level2)obj;
	writer.Write(level.entryDate().ToBinary());
	writer.Write(level.providerId());
	writer.Write(level.instrumentId());
	writer.Write(level.price());
	writer.Write(level.size());
	writer.Write((byte)level.side());
	writer.Write((byte)level.action());
	writer.Write(level.position());
}


// Pubic API 

Level2Streamer::Level2Streamer()
	: ObjectStreamer(*new Level2StreamerPrivate)
{
}

Level2Streamer::~Level2Streamer()
{
}


