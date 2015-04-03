#include <QuantKit/Streamer/StrategyStatusStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class StrategyStatusStreamerPrivate : public ObjectStreamerPrivate
{
public:
	StrategyStatusStreamerPrivate();
	virtual ~StrategyStatusStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual StrategyStatusStreamerPrivate* clone() Q_DECL_OVERRIDE { return new StrategyStatusStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

StrategyStatusStreamerPrivate::StrategyStatusStreamerPrivate()
{
		m_typeId = 20;
		m_type = typeof(StrategyStatusInfo);
}

StrategyStatusStreamerPrivate::~StrategyStatusStreamerPrivate ()
{
}

QVariant StrategyStatusStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	DateTime dateTime = new DateTime(reader.ReadInt64());
	StrategyStatusType type = (StrategyStatusType)reader.ReadByte();
	return new StrategyStatusInfo(dateTime, type)
	{
		Solution = reader.ReadString(),
		Mode = reader.ReadString()
	};
}

void StrategyStatusStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	StrategyStatusInfo strategyStatusInfo = obj as StrategyStatusInfo;
	writer.Write(strategyStatusInfo.dateTime().Ticks);
	writer.Write((byte)strategyStatusInfo.type());
	writer.Write(strategyStatusInfo.solution());
	writer.Write(strategyStatusInfo.mode());
}


// Pubic API 

StrategyStatusStreamer::StrategyStatusStreamer()
	: ObjectStreamer(*new StrategyStatusStreamerPrivate)
{
}

StrategyStatusStreamer::~StrategyStatusStreamer()
{
}


