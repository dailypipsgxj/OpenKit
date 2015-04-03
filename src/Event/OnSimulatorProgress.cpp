#include <QuantKit/Event/OnSimulatorProgress.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnSimulatorProgressPrivate : public DataObjectPrivate
{
public:
	long long_0;
	int int_0;

public:
	OnSimulatorProgressPrivate()
	{
		m_entryDate = DateTime.MinValue;
	}

	OnSimulatorProgressPrivate(long count, int percent);
	virtual ~OnSimulatorProgressPrivate();

public:
	long getLong_0() const;

	int getInt_0() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnSimulatorProgress;
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "OnSimulatorProgress"; }
	virtual OnSimulatorProgressPrivate* clone() Q_DECL_OVERRIDE { return new OnSimulatorProgressPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnSimulatorProgressPrivate::OnSimulatorProgressPrivate(long count, int percent)
	: long_0(count)
	, int_0(percent)
{
}

OnSimulatorProgressPrivate::~OnSimulatorProgressPrivate ()
{
}

long getLong_0() const
{
	return 0;
}

int getInt_0() const
{
	return 0;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnSimulatorProgress)

OnSimulatorProgress::OnSimulatorProgress()
	: DataObject(*new OnSimulatorProgressPrivate)
{
}

OnSimulatorProgress::OnSimulatorProgress(long count, int percent)
	: DataObject(*new OnSimulatorProgressPrivate(count, percent))
{
}

OnSimulatorProgress::~OnSimulatorProgress()
{
}

long long_0() const
{
	return d_ptr->
	setLong_0()
}

int int_0() const
{
	return d_ptr->
	setInt_0()
}


