#include <QuantKit/ReportManager.h>


namespace QuantKit {

class ReportManagerPrivate : public QSharedData
{
public:
	ReportManagerPrivate();
	virtual ~ReportManagerPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

ReportManagerPrivate::ReportManagerPrivate()
{
}

ReportManagerPrivate::~ReportManagerPrivate ()
{
}


// Pubic API 

ReportManager::ReportManager()
	: d_ptr(new ReportManagerPrivate)
{
}

ReportManager::~ReportManager()
{
}

ReportManager::ReportManager (const ReportManager &other)
	: d_ptr(other.d_ptr)
{
}

ReportManager& ReportManager::operator=(const ReportManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ReportManager::operator==(const ReportManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const ReportManager& reportmanager)
{
	return dbg << reportmanager.toString();
}

