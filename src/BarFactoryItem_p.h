#ifndef __QUANTKIT_BARFACTORYITEM_PRIVATE_H__
#define __QUANTKIT_BARFACTORYITEM_PRIVATE_H__

#include <QuantKit/BarFactoryItem.h>

#include <QSharedData>

#include "Instrument_p.h"
#include "DataObject_p.h"
#include "BarFactory_p.h"
#include "Bar_p.h"

namespace QuantKit {

class BarFactoryItemPrivate : public QSharedData
{
public:
	BarFactory m_factory;
	Instrument m_instrument;
	BarType m_barType;
	long m_barSize;
	BarInput m_barInput;
	bool m_sessionEnabled;
	TimeSpan session1;
	TimeSpan session2;
	Bar bar;

public:
	BarFactoryItemPrivate(const Instrument& instrument, BarType barType, long barSize, BarInput barInput);
	BarFactoryItemPrivate(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	virtual ~BarFactoryItemPrivate();

public:
	BarFactory getFactory() const;
	void setFactory(BarFactory value);
	Instrument getInstrument() const;

	long getBarSize() const;

	BarInput getBarInput() const;

	TimeSpan getSession1() const;

	TimeSpan getSession2() const;

	Bar getBar() const;
	virtual QString toString() const Q_DECL_OVERRIDE { return "BarFactoryItem"; }
//protected
	bool addReminder(const QDateTime& datetime, ClockType type)
	{
		return m_factory.method_2(this, datetime, type);
	}

	void emitBar();
	virtual QDateTime getBarCloseDateTime(const DataObject& obj) Q_DECL_OVERRIDE { return obj.entryDate(); }
	virtual QDateTime getBarOpenDateTime(const DataObject& obj) Q_DECL_OVERRIDE { return obj.entryDate(); }
	virtual QDateTime getDataObjectDateTime(const DataObject& obj, ClockType type) Q_DECL_OVERRIDE;
	virtual bool inSession(const QDateTime& dateTime) Q_DECL_OVERRIDE;
	void method_0(const DataObject& dataObject);
	virtual void onData(const DataObject& obj) Q_DECL_OVERRIDE;
	virtual void onReminder(const QDateTime& datetime) Q_DECL_OVERRIDE;
};

} // namepsace QuantKit

#endif // __QUANTKIT_BARFACTORYITEM_PRIVATE_H__
