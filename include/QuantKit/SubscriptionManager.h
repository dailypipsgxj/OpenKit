#ifndef __QUANTKIT_SUBSCRIPTIONMANAGER_H__
#define __QUANTKIT_SUBSCRIPTIONMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QSharedDataPointer>

#include <QuantKit/IDataProvider.h>

namespace QuantKit {

class SubscriptionManagerPrivate;

class Framework;
class Instrument;
class InstrumentList;

class QUANTKIT_EXPORT SubscriptionManager
{
public:
	explicit SubscriptionManager(const Framework& framework);
	~SubscriptionManager();

	SubscriptionManager(const SubscriptionManager &other);
	SubscriptionManager& operator=(const SubscriptionManager &other);
	bool operator==(const SubscriptionManager &other) const;
	inline bool operator!=(const SubscriptionManager &other) const { return !(this->operator==(other));  }
public:
	void clear();
	bool isSubscribed(const IDataProvider& provider, const Instrument& instrument);
	void subscribe(int providerId, const Instrument& instrument);
	void subscribe(int providerId, int instrumentId);
	void subscribe(const QString& provider, const Instrument& instrument);
	void subscribe(const QString& provider, const QString& symbol);
	void subscribe(const IDataProvider& provider, const Instrument& instrument);
	void subscribe(const IDataProvider& provider, const InstrumentList& instruments);
	void unsubscribe(int providerId, const Instrument& instrument);
	void unsubscribe(int providerId, int instrumentId);
	void unsubscribe(const IDataProvider& provider, const Instrument& instrument);
	void unsubscribe(const QString& provider, const Instrument& instrument);
	void unsubscribe(const QString& provider, const QString& symbol);
	void unsubscribe(const IDataProvider& provider, const InstrumentList& instruments);

private:
	QSharedDataPointer<SubscriptionManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const SubscriptionManager& subscriptionmanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const SubscriptionManager& subscriptionmanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::SubscriptionManager)

#endif // __QUANTKIT_SUBSCRIPTIONMANAGER_H__
