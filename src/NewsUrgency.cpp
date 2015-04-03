#include <QuantKit/NewsUrgency.h>


namespace QuantKit {

class NewsUrgencyPrivate : public QSharedData
{
public:
	unsigned char Normal;
	unsigned char Flash;
	unsigned char Background;

public:
	NewsUrgencyPrivate();
	virtual ~NewsUrgencyPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

NewsUrgencyPrivate::NewsUrgencyPrivate()
{
}

NewsUrgencyPrivate::~NewsUrgencyPrivate ()
{
}


// Pubic API 

NewsUrgency::NewsUrgency()
	: d_ptr(new NewsUrgencyPrivate)
{
}

NewsUrgency::~NewsUrgency()
{
}

NewsUrgency::NewsUrgency (const NewsUrgency &other)
	: d_ptr(other.d_ptr)
{
}

NewsUrgency& NewsUrgency::operator=(const NewsUrgency &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool NewsUrgency::operator==(const NewsUrgency &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const NewsUrgency& newsurgency)
{
	return dbg << newsurgency.toString();
}

