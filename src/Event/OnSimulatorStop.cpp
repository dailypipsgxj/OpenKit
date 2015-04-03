#include <QuantKit/Event/OnSimulatorStop.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnSimulatorStopPrivate : public DataObjectPrivate
{
public:
	OnSimulatorStopPrivate()
	{
		m_entryDate = DateTime.MinValue;
	}

	virtual ~OnSimulatorStopPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnSimulatorStop;
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "OnSimulatorStop"; }
	virtual OnSimulatorStopPrivate* clone() Q_DECL_OVERRIDE { return new OnSimulatorStopPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnSimulatorStopPrivate::~OnSimulatorStopPrivate ()
{
}


// Pubic API 

OnSimulatorStop::OnSimulatorStop()
	: DataObject(*new OnSimulatorStopPrivate)
{
}

OnSimulatorStop::~OnSimulatorStop()
{
}


