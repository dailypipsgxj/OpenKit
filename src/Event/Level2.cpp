#include <QuantKit/Event/Level2.h>

#include "Tick_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class Level2Private : public TickPrivate
{
public:
	Level2Side m_side;
	GEnum0 m_action;
	int m_position;

public:
	Level2Private();
	Level2Private(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size, Level2Side side, GEnum0 action, int position);
	virtual ~Level2Private();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Level2; }
	Level2Side side() const { return m_side; }
	void setSide(Level2Side value) { m_side = value; }
	GEnum0 action() const { return m_action; }
	void setAction(GEnum0 value) { m_action = value; }
	int position() const { return m_position; }
	void setPosition(int value) { m_position = value; }
	virtual Level2Private* clone() Q_DECL_OVERRIDE { return new Level2Private(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

Level2Private::Level2Private()
{
}

Level2Private::Level2Private(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size, Level2Side side, GEnum0 action, int position)
	: TickPrivate (dateTime, providerId, instrumentId, price, size)
	, m_side(side)
	, m_action(action)
	, m_position(position)
{
}

Level2Private::~Level2Private ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Level2)

Level2::Level2()
	: Tick(*new Level2Private)
{
}

Level2::Level2(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size, Level2Side side, GEnum0 action, int position)
	: Tick(*new Level2Private(dateTime, providerId, instrumentId, price, size, side, action, position))
{
}

Level2::~Level2()
{
}

Level2Side Level2::side() const
{
	Q_D(const Level2);
	return d->side();
}

void Level2::setSide(Level2Side value)
{
	Q_D(Level2);
	d->setSide(value);
}

GEnum0 Level2::action() const
{
	Q_D(const Level2);
	return d->action();
}

void Level2::setAction(GEnum0 value)
{
	Q_D(Level2);
	d->setAction(value);
}

int Level2::position() const
{
	Q_D(const Level2);
	return d->position();
}

void Level2::setPosition(int value)
{
	Q_D(Level2);
	d->setPosition(value);
}


