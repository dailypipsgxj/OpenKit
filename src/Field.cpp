#include <QuantKit/Field.h>


namespace QuantKit {

class FieldPrivate : public QSharedData
{
public:
	double double_0;

public:
	FieldPrivate();
	virtual ~FieldPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

FieldPrivate::FieldPrivate()
{
}

FieldPrivate::~FieldPrivate ()
{
}


// Pubic API 

Field::Field()
	: d_ptr(new FieldPrivate)
{
}

Field::~Field()
{
}

Field::Field (const Field &other)
	: d_ptr(other.d_ptr)
{
}

Field& Field::operator=(const Field &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Field::operator==(const Field &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const Field& field)
{
	return dbg << field.toString();
}

