#include <QuantKit/Event/SolutionStatusInfo.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class SolutionStatusInfoPrivate : public DataObjectPrivate
{
public:
	SolutionStatusType m_type;
	QString m_solution;
	QString m_mode;

public:
	SolutionStatusInfoPrivate(const QDateTime& dateTime, SolutionStatusType type) { base.setDateTime() = dateTime; }
	virtual ~SolutionStatusInfoPrivate();

public:
	SolutionStatusType type() const { return m_type; }
	QString solution() const { return m_solution; }
	void setSolution(const QString& value) { m_solution = value; }
	QString mode() const { return m_mode; }
	void setMode(const QString& value) { m_mode = value; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::SolutionStatusInfo;
	}

	virtual SolutionStatusInfoPrivate* clone() Q_DECL_OVERRIDE { return new SolutionStatusInfoPrivate(*this); }
//private:
	void setType(SolutionStatusType value) { m_type = value; }
};

} // namepsace QuantKit


using namespace QuantKit;

SolutionStatusInfoPrivate::~SolutionStatusInfoPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(SolutionStatusInfo)

SolutionStatusInfo::SolutionStatusInfo(const QDateTime& dateTime, SolutionStatusType type)
	: DataObject(*new SolutionStatusInfoPrivate(dateTime, type))
{
}

SolutionStatusInfo::~SolutionStatusInfo()
{
}

SolutionStatusType SolutionStatusInfo::type() const
{
	Q_D(const SolutionStatusInfo);
	return d->type();
}

QString SolutionStatusInfo::solution() const
{
	Q_D(const SolutionStatusInfo);
	return d->solution();
}

void SolutionStatusInfo::setSolution(const QString& value)
{
	Q_D(SolutionStatusInfo);
	d->setSolution(value);
}

QString SolutionStatusInfo::mode() const
{
	Q_D(const SolutionStatusInfo);
	return d->mode();
}

void SolutionStatusInfo::setMode(const QString& value)
{
	Q_D(SolutionStatusInfo);
	d->setMode(value);
}


