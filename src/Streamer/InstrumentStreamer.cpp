#include <QuantKit/Streamer/InstrumentStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class InstrumentStreamerPrivate : public ObjectStreamerPrivate
{
public:
	InstrumentStreamerPrivate();
	virtual ~InstrumentStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual InstrumentStreamerPrivate* clone() Q_DECL_OVERRIDE { return new InstrumentStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

InstrumentStreamerPrivate::InstrumentStreamerPrivate()
{
		m_typeId = 106;
		m_type = typeof(Instrument);
		version = 5;
}

InstrumentStreamerPrivate::~InstrumentStreamerPrivate ()
{
}

QVariant InstrumentStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	int id = reader.ReadInt32();
	InstrumentType type = (InstrumentType)reader.ReadByte();
	string symbol = reader.ReadString();
	string description = reader.ReadString();
	byte currencyId = reader.ReadByte();
	string exchange = reader.ReadString();
	Instrument instrument = new Instrument(id, type, symbol, description, currencyId, exchange);
	instrument.setTickSize() = reader.ReadDouble();
	instrument.setMaturity() = new DateTime(reader.ReadInt64());
	instrument.setFactor() = reader.ReadDouble();
	instrument.setStrike() = reader.ReadDouble();
	instrument.setPutCall() = (PutCall)reader.ReadByte();
	instrument.setMargin() = reader.ReadDouble();
	int num = reader.ReadInt32();
	for (int i = 0; i < num; i++)
	{
		instrument.altId().Add((AltId)m_streamerManager.Deserialize(reader));
	}
	int num2 = reader.ReadInt32();
	for (int j = 0; j < num2; j++)
	{
		instrument.legs().Add((Leg)m_streamerManager.Deserialize(reader));
	}
	if (version == 0)
	{
		int num3 = reader.ReadInt32();
		for (int k = 0; k < num3; k++)
		{
			instrument.fields()[k] = reader.ReadDouble();
		}
	}
	if (version >= 1)
	{
		instrument.setPriceFormat() = reader.ReadString();
	}
	if (version >= 1 && version <= 4)
	{
		int num4 = reader.ReadInt32();
		if (num4 != -1)
		{
			int id2 = (int)reader.ReadByte();
			byte version2 = reader.ReadByte();
			ObjectTable objectTable = new ObjectTable();
			int id3;
			while ((id3 = reader.ReadInt32()) != -1)
			{
				id2 = (int)reader.ReadByte();
				ObjectStreamer objectStreamer = m_streamerManager.idArray()[id2];
				objectTable.item()[id3] = objectStreamer.Read(reader, version2);
			}
			instrument.setFields() = objectTable;
		}
	}
	if (version >= 2)
	{
		instrument.setCCY1() = reader.ReadByte();
		instrument.setCCY2() = reader.ReadByte();
	}
	if (version >= 3)
	{
		instrument.setBool_0() = reader.ReadBoolean();
	}
	if (version >= 4)
	{
		instrument.setFormula() = reader.ReadString();
	}
	if (version >= 5)
	{
		int num5 = reader.ReadInt32();
		if (num5 != -1)
		{
			instrument.setFields() = (ObjectTable)m_streamerManager.Deserialize(reader);
		}
	}
	return instrument;
}

void InstrumentStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Instrument instrument = (Instrument)obj;
	writer.Write(instrument.id());
	writer.Write((byte)instrument.type());
	writer.Write(instrument.symbol());
	writer.Write(instrument.description());
	writer.Write(instrument.currencyId());
	writer.Write(instrument.exchange());
	writer.Write(instrument.tickSize());
	writer.Write(instrument.maturity().Ticks);
	writer.Write(instrument.factor());
	writer.Write(instrument.strike());
	writer.Write((byte)instrument.putCall());
	writer.Write(instrument.margin());
	writer.Write(instrument.altId().count());
	foreach (AltId current in instrument.altId())
	{
		m_streamerManager.Serialize(writer, current);
	}
	writer.Write(instrument.legs().Count);
	foreach (Leg current2 in instrument.legs())
	{
		m_streamerManager.Serialize(writer, current2);
	}
	if (version == 0)
	{
		writer.Write(instrument.fields().size());
		for (int i = 0; i < instrument.fields().size(); i++)
		{
			writer.Write((double)instrument.fields()[i]);
		}
	}
	if (version >= 1)
	{
		writer.Write(instrument.priceFormat());
	}
	if (version >= 2)
	{
		writer.Write(instrument.CCY1());
		writer.Write(instrument.CCY2());
	}
	if (version >= 3)
	{
		writer.Write(instrument.bool_0());
	}
	if (version >= 4)
	{
		writer.Write(instrument.formula());
	}
	if (version >= 5)
	{
		if (instrument.fields() == null)
		{
			writer.Write(-1);
			return;
		}
		writer.Write(instrument.fields().size());
		m_streamerManager.Serialize(writer, instrument.fields());
	}
}


// Pubic API 

InstrumentStreamer::InstrumentStreamer()
	: ObjectStreamer(*new InstrumentStreamerPrivate)
{
}

InstrumentStreamer::~InstrumentStreamer()
{
}


