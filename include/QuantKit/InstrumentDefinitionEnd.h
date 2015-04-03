#ifndef __QUANTKIT_INSTRUMENTDEFINITIONEND_H__
#define __QUANTKIT_INSTRUMENTDEFINITIONEND_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

#include <QuantKit/RequestResult.h>

namespace QuantKit {

class InstrumentDefinitionEndPrivate;

class QUANTKIT_EXPORT InstrumentDefinitionEnd
{
public:
	InstrumentDefinitionEnd();
	~InstrumentDefinitionEnd();

	InstrumentDefinitionEnd(const InstrumentDefinitionEnd &other);
	InstrumentDefinitionEnd& operator=(const InstrumentDefinitionEnd &other);
	bool operator==(const InstrumentDefinitionEnd &other) const;
	inline bool operator!=(const InstrumentDefinitionEnd &other) const { return !(this->operator==(other));  }
public:
	QString requestId() const;
	void setRequestId(const QString& value);
	RequestResult result() const;
	void setResult(RequestResult value);
	QString text() const;
	void setText(const QString& value);

private:
	QSharedDataPointer<InstrumentDefinitionEndPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const InstrumentDefinitionEnd& instrumentdefinitionend);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const InstrumentDefinitionEnd& instrumentdefinitionend);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentDefinitionEnd)

#endif // __QUANTKIT_INSTRUMENTDEFINITIONEND_H__
