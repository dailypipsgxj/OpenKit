#include <QuantKit/Streamer/ExecutionCommandStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class ExecutionCommandStreamerPrivate : public ObjectStreamerPrivate
{
public:
	ExecutionCommandStreamerPrivate();
	virtual ~ExecutionCommandStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual ExecutionCommandStreamerPrivate* clone() Q_DECL_OVERRIDE { return new ExecutionCommandStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ExecutionCommandStreamerPrivate::ExecutionCommandStreamerPrivate()
{
		m_typeId = 14;
		m_type = typeof(ExecutionCommand);
}

ExecutionCommandStreamerPrivate::~ExecutionCommandStreamerPrivate ()
{
}

QVariant ExecutionCommandStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	ExecutionCommand executionCommand = new ExecutionCommand();
	executionCommand.setId() = reader.ReadInt32();
	executionCommand.setType() = (ExecutionCommandType)reader.ReadByte();
	executionCommand.setTransactTime() = new DateTime(reader.ReadInt64());
	executionCommand.setOrderId() = reader.ReadInt32();
	executionCommand.setInstrumentId() = reader.ReadInt32();
	executionCommand.setProviderId() = reader.ReadByte();
	executionCommand.setRouteId() = reader.ReadByte();
	executionCommand.setPortfolioId() = reader.ReadInt32();
	executionCommand.setSide() = (OrderSide)reader.ReadByte();
	executionCommand.setOrdType() = (OrderType)reader.ReadByte();
	executionCommand.setTimeInForce() = (TimeInForce)reader.ReadByte();
	executionCommand.setPrice() = reader.ReadDouble();
	executionCommand.setStopPx() = reader.ReadDouble();
	executionCommand.setQty() = reader.ReadDouble();
	executionCommand.setOCA() = reader.ReadString();
	executionCommand.setText() = reader.ReadString();
	if (reader.ReadBoolean())
	{
		executionCommand.setAccount() = reader.ReadString();
	}
	if (reader.ReadBoolean())
	{
		executionCommand.setClientID() = reader.ReadString();
	}
	if (reader.ReadBoolean())
	{
		executionCommand.setItem() = (ObjectTable)m_streamerManager.Deserialize(reader);
	}
	return executionCommand;
}

void ExecutionCommandStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	ExecutionCommand executionCommand = (ExecutionCommand)obj;
	writer.Write(executionCommand.id());
	writer.Write((byte)executionCommand.type());
	writer.Write(executionCommand.transactTime().Ticks);
	writer.Write(executionCommand.orderId());
	writer.Write(executionCommand.instrument().id());
	writer.Write(executionCommand.provider().id());
	writer.Write(executionCommand.routeId());
	writer.Write(executionCommand.portfolio().id());
	writer.Write((byte)executionCommand.side());
	writer.Write((byte)executionCommand.ordType());
	writer.Write((byte)executionCommand.timeInForce());
	writer.Write(executionCommand.price());
	writer.Write(executionCommand.stopPx());
	writer.Write(executionCommand.qty());
	writer.Write(executionCommand.OCA());
	writer.Write(executionCommand.text());
	if (executionCommand.account() != null)
	{
		writer.Write(true);
		writer.Write(executionCommand.account());
	}
	else
	{
		writer.Write(false);
	}
	if (executionCommand.clientID() != null)
	{
		writer.Write(true);
		writer.Write(executionCommand.clientID());
	}
	else
	{
		writer.Write(false);
	}
	if (executionCommand.item() != null)
	{
		writer.Write(true);
		m_streamerManager.Serialize(writer, executionCommand.item());
		return;
	}
	writer.Write(false);
}


// Pubic API 

ExecutionCommandStreamer::ExecutionCommandStreamer()
	: ObjectStreamer(*new ExecutionCommandStreamerPrivate)
{
}

ExecutionCommandStreamer::~ExecutionCommandStreamer()
{
}


