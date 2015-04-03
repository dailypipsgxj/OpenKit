#include <QuantKit/ObjectType.h>


namespace QuantKit {

class ObjectTypePrivate : public QSharedData
{
public:
	unsigned char DataSeries;
	unsigned char ObjectKeyList;
	unsigned char FreeKeyList;
	unsigned char ObjectKeyIdArray;
	unsigned char DataKeyIdArray;
	unsigned char Instrument;
	unsigned char AltId;
	unsigned char Leg;

public:
	ObjectTypePrivate();
	virtual ~ObjectTypePrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

ObjectTypePrivate::ObjectTypePrivate()
{
}

ObjectTypePrivate::~ObjectTypePrivate ()
{
}


// Pubic API 

ObjectType::ObjectType()
	: d_ptr(new ObjectTypePrivate)
{
}

ObjectType::~ObjectType()
{
}

ObjectType::ObjectType (const ObjectType &other)
	: d_ptr(other.d_ptr)
{
}

ObjectType& ObjectType::operator=(const ObjectType &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ObjectType::operator==(const ObjectType &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const ObjectType& objecttype)
{
	return dbg << objecttype.toString();
}

