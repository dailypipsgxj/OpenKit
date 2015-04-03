#include <QuantKit/Event/OnSimulatorStart.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnSimulatorStartPrivate : public DataObjectPrivate
{
public:
	QDateTime ymlVcTtugA;
	QDateTime dateTime_0;
	long long_0;

public:
	OnSimulatorStartPrivate();
	OnSimulatorStartPrivate(const QDateTime& dateTime1, const QDateTime& dateTime2, long count) { m_entryDate = dateTime1; }
	virtual ~OnSimulatorStartPrivate();

public:
	QDateTime getYmlVcTtugA() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnSimulatorStart;
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "OnSimulatorStart"; }
	virtual OnSimulatorStartPrivate* clone() Q_DECL_OVERRIDE { return new OnSimulatorStartPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnSimulatorStartPrivate::OnSimulatorStartPrivate()
{
}

OnSimulatorStartPrivate::~OnSimulatorStartPrivate ()
{
}

QDateTime getYmlVcTtugA() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnSimulatorStart)

OnSimulatorStart::OnSimulatorStart()
	: DataObject(*new OnSimulatorStartPrivate)
{
}

OnSimulatorStart::OnSimulatorStart(const QDateTime& dateTime1, const QDateTime& dateTime2, long count)
	: DataObject(*new OnSimulatorStartPrivate(dateTime1, dateTime2, count))
{
}

OnSimulatorStart::~OnSimulatorStart()
{
}

QDateTime ymlVcTtugA() const
{
	return d_ptr->
	setYmlVcTtugA()
}


