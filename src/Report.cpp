#include <QuantKit/Report.h>

#include "ReportItem_p.h"

namespace QuantKit {

class ReportPrivate : public QSharedData
{
public:
	QList<ReportItem> list_0;

public:
	ReportPrivate();
	virtual ~ReportPrivate();

public:
	void add(const ReportItem& item) { list_0.Add(item); }
	void clear();
	virtual ReportPrivate* clone() Q_DECL_OVERRIDE { return new ReportPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ReportPrivate::ReportPrivate()
	: list_0(new QList<ReportItem>())
{
}

ReportPrivate::~ReportPrivate ()
{
}

void ReportPrivate::clear()
{
	foreach (ReportItem current in list_0)
	{
		current.Clear();
	}
}


// Pubic API 

Report::Report()
	: d_ptr(new ReportPrivate)
{
}

Report::~Report()
{
}

Report::Report (const Report &other)
	: d_ptr(other.d_ptr)
{
}

Report& Report::operator=(const Report &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Report::operator==(const Report &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void Report::add(const ReportItem& item)
{
	d_ptr->add(item);
}

void Report::clear()
{
	d_ptr->clear();
}

QDebug operator<<(QDebug dbg, const Report& report)
{
	return dbg << report.toString();
}

