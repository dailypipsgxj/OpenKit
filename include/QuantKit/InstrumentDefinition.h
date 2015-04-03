#ifndef __QUANTKIT_INSTRUMENTDEFINITION_H__
#define __QUANTKIT_INSTRUMENTDEFINITION_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class InstrumentDefinitionPrivate;

class Instrument;

class QUANTKIT_EXPORT InstrumentDefinition
{
public:
	InstrumentDefinition();
	~InstrumentDefinition();

	InstrumentDefinition(const InstrumentDefinition &other);
	InstrumentDefinition& operator=(const InstrumentDefinition &other);
	bool operator==(const InstrumentDefinition &other) const;
	inline bool operator!=(const InstrumentDefinition &other) const { return !(this->operator==(other));  }
public:
	QString requestId() const;
	void setRequestId(const QString& value);
	unsigned char providerId() const;
	void setProviderId(unsigned char value);
	int totalNum() const;
	void setTotalNum(int value);
	Instrument instruments() const;
	void setInstruments(const Instrument& value);

private:
	QSharedDataPointer<InstrumentDefinitionPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const InstrumentDefinition& instrumentdefinition);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const InstrumentDefinition& instrumentdefinition);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentDefinition)

#endif // __QUANTKIT_INSTRUMENTDEFINITION_H__
