#include <QuantKit/Event/AccountData.h>

#include <QuantKit/AccountDataFieldList.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class AccountDataPrivate : public DataObjectPrivate
{
public:
	AccountDataType m_type;
	QString m_account;
	unsigned char m_providerId;
	unsigned char m_route;
	AccountDataFieldList m_fields;

public:
	AccountDataPrivate(const QDateTime& datetime, AccountDataType type, const QString& account, unsigned char providerId, unsigned char route);
	virtual ~AccountDataPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::AccountData; }
	AccountDataType type() const { return m_type; }
	QString account() const { return m_account; }
	unsigned char providerId() const { return m_providerId; }
	unsigned char route() const { return m_route; }
	AccountDataFieldList fields() const { return m_fields; }
	virtual AccountDataPrivate* clone() Q_DECL_OVERRIDE { return new AccountDataPrivate(*this); }
//private:
	void setType(AccountDataType value) { m_type = value; }
	void setAccount(const QString& value) { m_account = value; }
	void setProviderId(unsigned char value) { m_providerId = value; }
	void setRoute(unsigned char value) { m_route = value; }
	void setFields(const AccountDataFieldList& value) { m_fields = value; }
};

} // namepsace QuantKit


using namespace QuantKit;

AccountDataPrivate::AccountDataPrivate(const QDateTime& datetime, AccountDataType type, const QString& account, unsigned char providerId, unsigned char route)
	: DataObjectPrivate (datetime)
	, m_type(type)
	, m_account(account)
	, m_providerId(providerId)
	, m_route(route)
	, m_fields(new AccountDataFieldList())
{
}

AccountDataPrivate::~AccountDataPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(AccountData)

AccountData::AccountData(const QDateTime& datetime, AccountDataType type, const QString& account, unsigned char providerId, unsigned char route)
	: DataObject(*new AccountDataPrivate(datetime, type, account, providerId, route))
{
}

AccountData::~AccountData()
{
}

AccountDataType AccountData::type() const
{
	Q_D(const AccountData);
	return d->type();
}

QString AccountData::account() const
{
	Q_D(const AccountData);
	return d->account();
}

unsigned char AccountData::providerId() const
{
	Q_D(const AccountData);
	return d->providerId();
}

unsigned char AccountData::route() const
{
	Q_D(const AccountData);
	return d->route();
}

AccountDataFieldList AccountData::fields() const
{
	Q_D(const AccountData);
	return d->fields();
}


