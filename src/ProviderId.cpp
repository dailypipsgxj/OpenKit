#include <QuantKit/ProviderId.h>


namespace QuantKit {

class ProviderIdPrivate : public QSharedData
{
public:
	unsigned char DataSimulator;
	unsigned char ExecutionSimulator;
	unsigned char byte_0;
	unsigned char IB;
	unsigned char ESignal;
	unsigned char byte_1;
	unsigned char Opentick;
	unsigned char QuoteTracker;
	unsigned char TAL;
	unsigned char TTFIX;
	unsigned char TTAPI;
	unsigned char Genesis;
	unsigned char MyTrack;
	unsigned char Photon;
	unsigned char Bloomberg;
	unsigned char Reuters;
	unsigned char Yahoo;
	unsigned char DC;
	unsigned char CSI;
	unsigned char QuantHouse;
	unsigned char PATSAPI;
	unsigned char OpenECry;
	unsigned char OpenTick;
	unsigned char FIX;
	unsigned char Google;
	unsigned char Hotspot;
	unsigned char AlfaDirect;
	unsigned char Currenex;
	unsigned char SmartCOM;
	unsigned char byte_2;
	unsigned char QUIKFIX;
	unsigned char OSLFIX;
	unsigned char Nordnet;
	unsigned char Integral;
	unsigned char QuantBase;
	unsigned char QuantRouter;
	unsigned char IQFeed;
	unsigned char QuantRouter2014;
	unsigned char MNI;
	unsigned char MatchingEngine;
	Class73 class73_0;

public:
	ProviderIdPrivate();
	virtual ~ProviderIdPrivate();

public:
	void add(const QString& name, unsigned char id)
	{
		ProviderId.class73_0().Add(name, id);
	}

	unsigned char get(const QString& name);
	void remove(const QString& name)
	{
		ProviderId.class73_0().Remove(name);
	}

	virtual ProviderIdPrivate* clone() Q_DECL_OVERRIDE { return new ProviderIdPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ProviderIdPrivate::ProviderIdPrivate()
{
}

ProviderIdPrivate::~ProviderIdPrivate ()
{
}

unsigned char ProviderIdPrivate::get(const QString& name)
{
	byte result;
	ProviderId.class73_0().TryGetValue(name, out result);
	return result;
}


// Pubic API 

ProviderId::ProviderId()
	: d_ptr(new ProviderIdPrivate)
{
}

ProviderId::~ProviderId()
{
}

ProviderId::ProviderId (const ProviderId &other)
	: d_ptr(other.d_ptr)
{
}

ProviderId& ProviderId::operator=(const ProviderId &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ProviderId::operator==(const ProviderId &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void ProviderId::add(const QString& name, unsigned char id)
{
	d_ptr->add(name, id);
}

unsigned char ProviderId::get(const QString& name)
{
	return d_ptr->get(name);
}

void ProviderId::remove(const QString& name)
{
	d_ptr->remove(name);
}

QDebug operator<<(QDebug dbg, const ProviderId& providerid)
{
	return dbg << providerid.toString();
}

