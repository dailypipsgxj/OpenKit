#ifndef __QUANTKIT_INSTRUMENTDEFINITIONENDEVENTHANDLER_H__
#define __QUANTKIT_INSTRUMENTDEFINITIONENDEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class InstrumentDefinitionEndEventHandlerPrivate;

class InstrumentDefinitionEndEventArgs;

class QUANTKIT_EXPORT InstrumentDefinitionEndEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	InstrumentDefinitionEndEventHandler(const QVariant& object, IntPtr method);
	~InstrumentDefinitionEndEventHandler();

	InstrumentDefinitionEndEventHandler(const InstrumentDefinitionEndEventHandler &other);
	InstrumentDefinitionEndEventHandler& operator=(const InstrumentDefinitionEndEventHandler &other);
	bool operator==(const InstrumentDefinitionEndEventHandler &other) const;
	inline bool operator!=(const InstrumentDefinitionEndEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const InstrumentDefinitionEndEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const InstrumentDefinitionEndEventArgs& e);

private:
	QSharedDataPointer<InstrumentDefinitionEndEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const InstrumentDefinitionEndEventHandler& instrumentdefinitionendeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const InstrumentDefinitionEndEventHandler& instrumentdefinitionendeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentDefinitionEndEventHandler)

#endif // __QUANTKIT_INSTRUMENTDEFINITIONENDEVENTHANDLER_H__
