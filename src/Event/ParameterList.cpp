#include <QuantKit/Event/ParameterList.h>

#include <QuantKit/Parameter.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class ParameterListPrivate : public DataObjectPrivate
{
public:
	QList<Parameter> m_item;
	QList<QString> methods;
	QString m_strategyName;

public:
	ParameterListPrivate();
	virtual ~ParameterListPrivate();

public:
	QList<QString> getMethods() const;
	QString strategyName() const { return m_strategyName; }
	void setStrategyName(const QString& value) { m_strategyName = value; }
	Parameter item(int index) const { return m_item[index]; }
	void setItem(int index, const Parameter& value) { m_item[index] = value; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::ParameterList;
	}

	void add(const Parameter& parameter) { m_item.Add(parameter); }
	void clear() { m_item.Clear(); }
	int count() { return m_item.Count; }
	IEnumerator<Parameter> getEnumerator() { return m_item.GetEnumerator(); }
	QList<Parameter> parameters() { return m_item; }
	void remove(const Parameter& parameter) { m_item.Remove(parameter); }
	virtual ParameterListPrivate* clone() Q_DECL_OVERRIDE { return new ParameterListPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ParameterListPrivate::ParameterListPrivate()
	: m_item(new QList<Parameter>())
	, methods(new QList<string>())
{
}

ParameterListPrivate::~ParameterListPrivate ()
{
}

QList<QString> getMethods() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(ParameterList)

ParameterList::ParameterList()
	: DataObject(*new ParameterListPrivate)
{
}

ParameterList::~ParameterList()
{
}

QList<QString> methods() const
{
	return d_ptr->
	setMethods()
}

QString ParameterList::strategyName() const
{
	Q_D(const ParameterList);
	return d->strategyName();
}

void ParameterList::setStrategyName(const QString& value)
{
	Q_D(ParameterList);
	d->setStrategyName(value);
}

Parameter ParameterList::item(int index) const
{
	Q_D(const ParameterList);
	return d->item(index);
}

void ParameterList::setItem(int index, const Parameter& value)
{
	Q_D(ParameterList);
	d->setItem(index, value);
}

void ParameterList::add(const Parameter& parameter)
{
	Q_D(ParameterList);
	d->add(parameter);
}

void ParameterList::clear()
{
	Q_D(ParameterList);
	d->clear();
}

int ParameterList::count()
{
	Q_D(ParameterList);
	return d->count();
}

IEnumerator<Parameter> ParameterList::getEnumerator()
{
	Q_D(ParameterList);
	return d->getEnumerator();
}

QList<Parameter> ParameterList::parameters()
{
	Q_D(ParameterList);
	return d->parameters();
}

void ParameterList::remove(const Parameter& parameter)
{
	Q_D(ParameterList);
	d->remove(parameter);
}


