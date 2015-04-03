#ifndef __QUANTKIT_PROVIDER_H__
#define __QUANTKIT_PROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

#include <QuantKit/IProvider.h>
#include <QuantKit/ProviderStatus.h>
#include <QuantKit/RequestResult.h>

namespace QuantKit {

class ProviderPrivate;

class Framework;
class Event;
class Instrument;
class InstrumentList;
class ExecutionCommand;
class HistoricalDataRequest;
class InstrumentDefinitionRequest;
class ProviderError;
class DataObject;
class ExecutionReport;
class AccountData;
class HistoricalData;
class HistoricalDataEnd;
class InstrumentDefinition;
class InstrumentDefinitionEnd;
class ProviderPropertyList;
class EventQueue;

class QUANTKIT_EXPORT Provider : public IProvider
{
public:
	explicit Provider(const Framework& framework);
	~Provider();

	Provider(const Provider &other);
	Provider& operator=(const Provider &other);
	bool operator==(const Provider &other) const;
	inline bool operator!=(const Provider &other) const { return !(this->operator==(other));  }
public:
	Framework framework() const;
	unsigned char id() const;
	QString name() const;
	QString description() const;
	QString url() const;
	ProviderStatus status() const;
	bool isConnected() const;
	bool isDisconnected() const;
	void connect();
	bool connect(int timeout);
	void disconnect();
	void dispose();
	void process(const Event& e);
	void requestHistoricalData(const HistoricalDataRequest& request);
	void requestInstrumentDefinitions(const InstrumentDefinitionRequest& request);
	void send(const ExecutionCommand& command);
	void send(const HistoricalDataRequest& request);
	void send(const InstrumentDefinitionRequest& request);
	void subscribe(const Instrument& instrument);
	void subscribe(const InstrumentList& instruments);
	QString toString() const;
	void unsubscribe(const Instrument& instrument);
	void unsubscribe(const InstrumentList& instruments);

protected:
	Provider(ProviderPrivate& dd);
	QSharedDataPointer<ProviderPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const Provider& provider);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Provider& provider);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Provider)

#endif // __QUANTKIT_PROVIDER_H__
