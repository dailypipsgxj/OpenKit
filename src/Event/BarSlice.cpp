#include <QuantKit/Event/BarSlice.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class BarSlicePrivate : public EventPrivate
{
public:
	long m_size;

public:
	explicit BarSlicePrivate(long size);
	virtual ~BarSlicePrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::BarSlice; }
	long size() const { return m_size; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "BarSlice"; }
	virtual BarSlicePrivate* clone() Q_DECL_OVERRIDE { return new BarSlicePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

BarSlicePrivate::BarSlicePrivate(long size)
	: m_size(size)
{
}

BarSlicePrivate::~BarSlicePrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(BarSlice)

BarSlice::BarSlice(long size)
	: Event(*new BarSlicePrivate(size))
{
}

BarSlice::~BarSlice()
{
}

long BarSlice::size() const
{
	Q_D(const BarSlice);
	return d->size();
}


