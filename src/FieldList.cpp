#include <QuantKit/FieldList.h>

#include <QuantKit/IdArray.h>

namespace QuantKit {

class FieldListPrivate : public QSharedData
{
public:
	IdArray<double> m_idArray;

public:
	FieldListPrivate();
	virtual ~FieldListPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

FieldListPrivate::FieldListPrivate()
	: m_idArray(new IdArray<double>(1000))
{
}

FieldListPrivate::~FieldListPrivate ()
{
}


// Pubic API 

FieldList::FieldList()
	: d_ptr(new FieldListPrivate)
{
}

FieldList::~FieldList()
{
}

FieldList::FieldList (const FieldList &other)
	: d_ptr(other.d_ptr)
{
}

FieldList& FieldList::operator=(const FieldList &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool FieldList::operator==(const FieldList &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const FieldList& fieldlist)
{
	return dbg << fieldlist.toString();
}

