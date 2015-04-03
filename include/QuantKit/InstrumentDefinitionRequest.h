#ifndef __QUANTKIT_INSTRUMENTDEFINITIONREQUEST_H__
#define __QUANTKIT_INSTRUMENTDEFINITIONREQUEST_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

#include <QuantKit/InstrumentType.h>

namespace QuantKit {

class InstrumentDefinitionRequestPrivate;

class QUANTKIT_EXPORT InstrumentDefinitionRequest
{
public:
	InstrumentDefinitionRequest();
	~InstrumentDefinitionRequest();

	InstrumentDefinitionRequest(const InstrumentDefinitionRequest &other);
	InstrumentDefinitionRequest& operator=(const InstrumentDefinitionRequest &other);
	bool operator==(const InstrumentDefinitionRequest &other) const;
	inline bool operator!=(const InstrumentDefinitionRequest &other) const { return !(this->operator==(other));  }
public:
	QString id() const;
	void setId(const QString& value);
    Nullable<InstrumentType> filterType() const;
    void setFilterType(const Nullable<InstrumentType>& value);
	QString filterSymbol() const;
	void setFilterSymbol(const QString& value);
	QString filterExchange() const;
	void setFilterExchange(const QString& value);

private:
	QSharedDataPointer<InstrumentDefinitionRequestPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const InstrumentDefinitionRequest& instrumentdefinitionrequest);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const InstrumentDefinitionRequest& instrumentdefinitionrequest);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentDefinitionRequest)

#endif // __QUANTKIT_INSTRUMENTDEFINITIONREQUEST_H__
