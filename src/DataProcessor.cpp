#include <QuantKit/DataProcessor.h>

#include "DataObject_p.h"

namespace QuantKit {

class DataProcessorPrivate : public QSharedData
{
public:
	Class52 class52_0;
	bool m_emitBar;
	bool m_emitBarOpen;
	bool m_emitBarOpenTrade;
	bool m_emitBarHighTrade;
	bool m_emitBarLowTrade;
	bool m_emitBarCloseTrade;

public:
	DataProcessorPrivate();
	virtual ~DataProcessorPrivate();

public:
	bool emitBar() const { return m_emitBar; }
	void setEmitBar(bool value) { m_emitBar = value; }
	bool emitBarOpen() const { return m_emitBarOpen; }
	void setEmitBarOpen(bool value) { m_emitBarOpen = value; }
	bool emitBarOpenTrade() const { return m_emitBarOpenTrade; }
	void setEmitBarOpenTrade(bool value) { m_emitBarOpenTrade = value; }
	bool emitBarHighTrade() const { return m_emitBarHighTrade; }
	void setEmitBarHighTrade(bool value) { m_emitBarHighTrade = value; }
	bool emitBarLowTrade() const { return m_emitBarLowTrade; }
	void setEmitBarLowTrade(bool value) { m_emitBarLowTrade = value; }
	bool emitBarCloseTrade() const { return m_emitBarCloseTrade; }
	void setEmitBarCloseTrade(bool value) { m_emitBarCloseTrade = value; }
	virtual DataProcessorPrivate* clone() Q_DECL_OVERRIDE { return new DataProcessorPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DataProcessorPrivate::DataProcessorPrivate()
	: m_emitBar(true)
	, m_emitBarOpen(true)
{
}

DataProcessorPrivate::~DataProcessorPrivate ()
{
}


// Pubic API 

DataProcessor::DataProcessor()
	: d_ptr(new DataProcessorPrivate)
{
}

DataProcessor::~DataProcessor()
{
}

DataProcessor::DataProcessor (const DataProcessor &other)
	: d_ptr(other.d_ptr)
{
}

DataProcessor& DataProcessor::operator=(const DataProcessor &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataProcessor::operator==(const DataProcessor &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

bool DataProcessor::emitBar() const
{
	return d_ptr->emitBar();
}

void DataProcessor::setEmitBar(bool value)
{
	d_ptr->setEmitBar(value);
}

bool DataProcessor::emitBarOpen() const
{
	return d_ptr->emitBarOpen();
}

void DataProcessor::setEmitBarOpen(bool value)
{
	d_ptr->setEmitBarOpen(value);
}

bool DataProcessor::emitBarOpenTrade() const
{
	return d_ptr->emitBarOpenTrade();
}

void DataProcessor::setEmitBarOpenTrade(bool value)
{
	d_ptr->setEmitBarOpenTrade(value);
}

bool DataProcessor::emitBarHighTrade() const
{
	return d_ptr->emitBarHighTrade();
}

void DataProcessor::setEmitBarHighTrade(bool value)
{
	d_ptr->setEmitBarHighTrade(value);
}

bool DataProcessor::emitBarLowTrade() const
{
	return d_ptr->emitBarLowTrade();
}

void DataProcessor::setEmitBarLowTrade(bool value)
{
	d_ptr->setEmitBarLowTrade(value);
}

bool DataProcessor::emitBarCloseTrade() const
{
	return d_ptr->emitBarCloseTrade();
}

void DataProcessor::setEmitBarCloseTrade(bool value)
{
	d_ptr->setEmitBarCloseTrade(value);
}

QDebug operator<<(QDebug dbg, const DataProcessor& dataprocessor)
{
	return dbg << dataprocessor.toString();
}

