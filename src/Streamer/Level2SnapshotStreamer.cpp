#include <QuantKit/Streamer/Level2SnapshotStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class Level2SnapshotStreamerPrivate : public ObjectStreamerPrivate
{
public:
	Level2SnapshotStreamerPrivate();
	virtual ~Level2SnapshotStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual Level2SnapshotStreamerPrivate* clone() Q_DECL_OVERRIDE { return new Level2SnapshotStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

Level2SnapshotStreamerPrivate::Level2SnapshotStreamerPrivate()
{
		m_typeId = 8;
		m_type = typeof(Level2Snapshot);
}

Level2SnapshotStreamerPrivate::~Level2SnapshotStreamerPrivate ()
{
}

QVariant Level2SnapshotStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	Level2Snapshot level2Snapshot = new Level2Snapshot();
	level2Snapshot.setEntryDate() = DateTime.FromBinary(reader.ReadInt64());
	level2Snapshot.setByte_0() = reader.ReadByte();
	level2Snapshot.setInt_0() = reader.ReadInt32();
	int num = reader.ReadInt32();
	level2Snapshot.setBids() = new Bid[num];
	for (int i = 0; i < num; i++)
	{
		level2Snapshot.bids()[i] = (Bid)m_streamerManager.Deserialize(reader);
	}
	int num2 = reader.ReadInt32();
	level2Snapshot.setAsks() = new Ask[num2];
	for (int j = 0; j < num2; j++)
	{
		level2Snapshot.asks()[j] = (Ask)m_streamerManager.Deserialize(reader);
	}
	return level2Snapshot;
}

void Level2SnapshotStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Level2Snapshot level2Snapshot = (Level2Snapshot)obj;
	writer.Write(level2Snapshot.entryDate().ToBinary());
	writer.Write(level2Snapshot.byte_0());
	writer.Write(level2Snapshot.int_0());
	writer.Write(level2Snapshot.bids().Length);
	Bid[] bids = level2Snapshot.bids();
	for (int i = 0; i < bids.Length; i++)
	{
		Bid obj2 = bids[i];
		m_streamerManager.Serialize(writer, obj2);
	}
	writer.Write(level2Snapshot.asks().Length);
	Ask[] asks = level2Snapshot.asks();
	for (int j = 0; j < asks.Length; j++)
	{
		Ask obj3 = asks[j];
		m_streamerManager.Serialize(writer, obj3);
	}
}


// Pubic API 

Level2SnapshotStreamer::Level2SnapshotStreamer()
	: ObjectStreamer(*new Level2SnapshotStreamerPrivate)
{
}

Level2SnapshotStreamer::~Level2SnapshotStreamer()
{
}


