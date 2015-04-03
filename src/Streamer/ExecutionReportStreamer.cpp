#include <QuantKit/Streamer/ExecutionReportStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class ExecutionReportStreamerPrivate : public ObjectStreamerPrivate
{
public:
	ExecutionReportStreamerPrivate();
	virtual ~ExecutionReportStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual ExecutionReportStreamerPrivate* clone() Q_DECL_OVERRIDE { return new ExecutionReportStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ExecutionReportStreamerPrivate::ExecutionReportStreamerPrivate()
{
		m_typeId = 13;
		m_type = typeof(ExecutionReport);
}

ExecutionReportStreamerPrivate::~ExecutionReportStreamerPrivate ()
{
}

QVariant ExecutionReportStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	ExecutionReport executionReport = new ExecutionReport();
	executionReport.setDateTime() = new DateTime(reader.ReadInt64());
	executionReport.setOrderId() = reader.ReadInt32();
	executionReport.setInstrumentId() = reader.ReadInt32();
	executionReport.setCurrencyId() = reader.ReadByte();
	executionReport.setExecType() = (ExecType)reader.ReadByte();
	executionReport.setOrdStatus() = (OrderStatus)reader.ReadByte();
	executionReport.setOrdType() = (OrderType)reader.ReadByte();
	executionReport.setSide() = (OrderSide)reader.ReadByte();
	executionReport.setTimeInForce() = (TimeInForce)reader.ReadByte();
	executionReport.setPrice() = reader.ReadDouble();
	executionReport.setStopPx() = reader.ReadDouble();
	executionReport.setOrdQty() = reader.ReadDouble();
	executionReport.setCumQty() = reader.ReadDouble();
	executionReport.setLeavesQty() = reader.ReadDouble();
	executionReport.setLastPx() = reader.ReadDouble();
	executionReport.setLastQty() = reader.ReadDouble();
	executionReport.setCommission() = reader.ReadDouble();
	executionReport.setText() = reader.ReadString();
	if (reader.ReadBoolean())
	{
		executionReport.setItem() = (ObjectTable)m_streamerManager.Deserialize(reader);
	}
	return executionReport;
}

void ExecutionReportStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	ExecutionReport executionReport = (ExecutionReport)obj;
	writer.Write(executionReport.entryDate().Ticks);
	writer.Write(executionReport.orderId());
	writer.Write(executionReport.instrumentId());
	writer.Write(executionReport.currencyId());
	writer.Write((byte)executionReport.execType());
	writer.Write((byte)executionReport.ordStatus());
	writer.Write((byte)executionReport.ordType());
	writer.Write((byte)executionReport.side());
	writer.Write((byte)executionReport.timeInForce());
	writer.Write(executionReport.price());
	writer.Write(executionReport.stopPx());
	writer.Write(executionReport.ordQty());
	writer.Write(executionReport.cumQty());
	writer.Write(executionReport.leavesQty());
	writer.Write(executionReport.lastPx());
	writer.Write(executionReport.lastQty());
	writer.Write(executionReport.commission());
	writer.Write(executionReport.text());
	if (executionReport.item() != null)
	{
		writer.Write(true);
		m_streamerManager.Serialize(writer, executionReport.item());
		return;
	}
	writer.Write(false);
}


// Pubic API 

ExecutionReportStreamer::ExecutionReportStreamer()
	: ObjectStreamer(*new ExecutionReportStreamerPrivate)
{
}

ExecutionReportStreamer::~ExecutionReportStreamer()
{
}


