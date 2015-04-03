#include <QuantKit/ReportItem.h>

#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>
#include <QuantKit/Event/Trade.h>
#include <QuantKit/Event/Bar.h>
#include <QuantKit/Event/ExecutionReport.h>
#include "ReportItem_p.h"

using namespace QuantKit;

ReportItemPrivate::ReportItemPrivate()
{
}

ReportItemPrivate::~ReportItemPrivate ()
{
}

//protected
void ReportItemPrivate::clear()
{
}

void ReportItemPrivate::onAsk(const Ask& Ask)
{
}

void ReportItemPrivate::onBar(const Bar& bar)
{
}

void ReportItemPrivate::onBid(const Bid& bid)
{
}

void ReportItemPrivate::onExecutionReport(const ExecutionReport& report)
{
}

void ReportItemPrivate::onTrade(const Trade& trade)
{
}


// Pubic API 

ReportItem::ReportItem()
	: d_ptr(new ReportItemPrivate)
{
}

ReportItem::~ReportItem()
{
}

ReportItem::ReportItem (ReportItemPrivate &dd)
	: d_ptr(&dd)
{
}

ReportItem::ReportItem (const ReportItem &other)
	: d_ptr(other.d_ptr)
{
}

ReportItem& ReportItem::operator=(const ReportItem &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ReportItem::operator==(const ReportItem &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString ReportItem::name() const
{
	return d_ptr->name();
}

QString ReportItem::description() const
{
	return d_ptr->description();
}

QDebug operator<<(QDebug dbg, const ReportItem& reportitem)
{
	return dbg << reportitem.toString();
}

