#include <QuantKit/Event/StrategyStatusInfo.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class StrategyStatusInfoPrivate : public DataObjectPrivate
{
public:
	StrategyStatusType m_type;
	QString m_solution;
	QString m_mode;

public:
	StrategyStatusInfoPrivate(const QDateTime& dateTime, StrategyStatusType type) { base.setDateTime() = dateTime; }
	virtual ~StrategyStatusInfoPrivate();

public:
	StrategyStatusType type() const { return m_type; }
	QString solution() const { return m_solution; }
	void setSolution(const QString& value) { m_solution = value; }
	QString mode() const { return m_mode; }
	void setMode(const QString& value) { m_mode = value; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::StrategyStatusInfo;
	}

	virtual StrategyStatusInfoPrivate* clone() Q_DECL_OVERRIDE { return new StrategyStatusInfoPrivate(*this); }
//private:
	void setType(StrategyStatusType value) { m_type = value; }
};

} // namepsace QuantKit


using namespace QuantKit;

StrategyStatusInfoPrivate::~StrategyStatusInfoPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(StrategyStatusInfo)

StrategyStatusInfo::StrategyStatusInfo(const QDateTime& dateTime, StrategyStatusType type)
	: DataObject(*new StrategyStatusInfoPrivate(dateTime, type))
{
}

StrategyStatusInfo::~StrategyStatusInfo()
{
}

StrategyStatusType StrategyStatusInfo::type() const
{
	Q_D(const StrategyStatusInfo);
	return d->type();
}

QString StrategyStatusInfo::solution() const
{
	Q_D(const StrategyStatusInfo);
	return d->solution();
}

void StrategyStatusInfo::setSolution(const QString& value)
{
	Q_D(StrategyStatusInfo);
	d->setSolution(value);
}

QString StrategyStatusInfo::mode() const
{
	Q_D(const StrategyStatusInfo);
	return d->mode();
}

void StrategyStatusInfo::setMode(const QString& value)
{
	Q_D(StrategyStatusInfo);
	d->setMode(value);
}


