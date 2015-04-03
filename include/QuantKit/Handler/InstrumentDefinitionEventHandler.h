#ifndef __QUANTKIT_INSTRUMENTDEFINITIONEVENTHANDLER_H__
#define __QUANTKIT_INSTRUMENTDEFINITIONEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class InstrumentDefinitionEventHandlerPrivate;

class InstrumentDefinitionEventArgs;

class QUANTKIT_EXPORT InstrumentDefinitionEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	InstrumentDefinitionEventHandler(const QVariant& object, IntPtr method);
	~InstrumentDefinitionEventHandler();

	InstrumentDefinitionEventHandler(const InstrumentDefinitionEventHandler &other);
	InstrumentDefinitionEventHandler& operator=(const InstrumentDefinitionEventHandler &other);
	bool operator==(const InstrumentDefinitionEventHandler &other) const;
	inline bool operator!=(const InstrumentDefinitionEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const InstrumentDefinitionEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const InstrumentDefinitionEventArgs& e);

private:
	QSharedDataPointer<InstrumentDefinitionEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const InstrumentDefinitionEventHandler& instrumentdefinitioneventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const InstrumentDefinitionEventHandler& instrumentdefinitioneventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentDefinitionEventHandler)

#endif // __QUANTKIT_INSTRUMENTDEFINITIONEVENTHANDLER_H__
