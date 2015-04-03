#ifndef __QUANTKIT_PROVIDER_PRIVATE_H__
#define __QUANTKIT_PROVIDER_PRIVATE_H__

#include <QuantKit/Provider.h>

#include <QSharedData>

#include "Framework_p.h"
#include "Event_p.h"
#include "Instrument_p.h"
#include "InstrumentList_p.h"
#include "ExecutionCommand_p.h"
#include "HistoricalDataRequest_p.h"
#include "InstrumentDefinitionRequest_p.h"
#include "ProviderError_p.h"
#include "DataObject_p.h"
#include "ExecutionReport_p.h"
#include "AccountData_p.h"
#include "HistoricalData_p.h"
#include "HistoricalDataEnd_p.h"
#include "InstrumentDefinition_p.h"
#include "InstrumentDefinitionEnd_p.h"
#include "ProviderPropertyList_p.h"
#include "EventQueue_p.h"

namespace QuantKit {

class ProviderPrivate : public QSharedData
{
public:
	QString CATEGORY_INFO;
	QString CATEGORY_STATUS;
	Framework framework;
	unsigned char m_id;
	QString m_name;
	QString m_description;
	QString m_url;
	ProviderStatus m_isDisconnected;
	EventQueue m_dataQueue;
	EventQueue m_executionQueue;
	EventQueue m_historicalQueue;
	EventQueue m_instrumentQueue;

public:
	explicit ProviderPrivate(const Framework& framework);
	virtual ~ProviderPrivate();

public:
	Framework getFramework() const;
	unsigned char id() const { return m_id; }
	QString name() const { return m_name; }
	QString description() const { return m_description; }
	QString url() const { return m_url; }
	ProviderStatus status() const { return m_isDisconnected; }
	bool isConnected() const
	{
		return m_isDisconnected == ProviderStatus.Connected;
	}

	bool isDisconnected() const
	{
		return m_isDisconnected == ProviderStatus.Disconnected;
	}

	virtual void connect() Q_DECL_OVERRIDE
	{
		m_isDisconnected = ProviderStatus.Connected;
	}

	bool connect(int timeout);
	virtual void disconnect() Q_DECL_OVERRIDE
	{
		m_isDisconnected = ProviderStatus.Disconnected;
	}

	void dispose();
	virtual void process(const Event& e) Q_DECL_OVERRIDE;
	virtual void requestHistoricalData(const HistoricalDataRequest& request) Q_DECL_OVERRIDE;
	virtual void requestInstrumentDefinitions(const InstrumentDefinitionRequest& request) Q_DECL_OVERRIDE;
	virtual void send(const ExecutionCommand& command) Q_DECL_OVERRIDE
	{
		Console.WriteLine("Provider::Send is not implemented in the base class");
	}

	virtual void send(const HistoricalDataRequest& request) Q_DECL_OVERRIDE;
	virtual void send(const InstrumentDefinitionRequest& request) Q_DECL_OVERRIDE;
	virtual void subscribe(const Instrument& instrument) Q_DECL_OVERRIDE;
	virtual void subscribe(const InstrumentList& instruments) Q_DECL_OVERRIDE;
	virtual QString toString() const Q_DECL_OVERRIDE { return "Provider"; }
	virtual void unsubscribe(const Instrument& instrument) Q_DECL_OVERRIDE;
	virtual void unsubscribe(const InstrumentList& instruments) Q_DECL_OVERRIDE;
//protected
	void setStatus(ProviderStatus value);
	virtual void dispose(bool disposing) Q_DECL_OVERRIDE;
	void emitAccountData(const AccountData& data);
	void emitData(const DataObject& data, bool queued);
	void emitError(int id, int code, const QString& text)
	{
		EmitProviderError(new ProviderError(framework.clock().dateTime(), ProviderErrorType.Error, m_id, id, code, text));
	}

	void emitError(const QString& text) { EmitError(-1, -1, text); }
	void emitExecutionReport(const ExecutionReport& report, bool queued);
	void emitHistoricalData(const HistoricalData& data);
	void emitHistoricalDataEnd(const HistoricalDataEnd& end);
	void emitHistoricalDataEnd(const QString& requestId, RequestResult result, const QString& text);
	void emitInstrumentDefinition(const InstrumentDefinition& definition);
	void emitInstrumentDefinitionEnd(const InstrumentDefinitionEnd& end);
	void emitInstrumentDefinitionEnd(const QString& requestId, RequestResult result, const QString& text);
	void emitMessage(int id, int code, const QString& text)
	{
		EmitProviderError(new ProviderError(framework.clock().dateTime(), ProviderErrorType.Message, m_id, id, code, text));
	}

	void emitMessage(const QString& text) { EmitMessage(-1, -1, text); }
	void emitProviderError(const ProviderError& error)
	{
		framework.eventServer().OnProviderError(error);
	}

	void emitWarning(int id, int code, const QString& text)
	{
		EmitProviderError(new ProviderError(framework.clock().dateTime(), ProviderErrorType.Warning, m_id, id, code, text));
	}

	void emitWarning(const QString& text) { EmitWarning(-1, -1, text); }
	virtual ProviderPropertyList getProperties() Q_DECL_OVERRIDE;
	virtual void onConnected() Q_DECL_OVERRIDE;
	virtual void onDisconnected() Q_DECL_OVERRIDE;
	virtual void setProperties(const ProviderPropertyList& properties) Q_DECL_OVERRIDE;

//private:
	void method_0();
	void method_1();
	void method_2();
	void method_3();
};

} // namepsace QuantKit

#endif // __QUANTKIT_PROVIDER_PRIVATE_H__
