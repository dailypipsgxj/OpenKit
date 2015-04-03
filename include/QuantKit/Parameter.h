#ifndef __QUANTKIT_PARAMETER_H__
#define __QUANTKIT_PARAMETER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class ParameterPrivate;

class QUANTKIT_EXPORT Parameter
{
public:
	Parameter(const QString& name, const QVariant& value);
	Parameter(const QString& name, const QVariant& value, const Attribute& attributes);
	~Parameter();

	Parameter(const Parameter &other);
	Parameter& operator=(const Parameter &other);
	bool operator==(const Parameter &other) const;
	inline bool operator!=(const Parameter &other) const { return !(this->operator==(other));  }
public:
	QString name() const;
	QVariant value() const;
	Attribute attributes() const;
	QString toString() const;

private:
	QSharedDataPointer<ParameterPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Parameter& parameter);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Parameter& parameter);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Parameter)

#endif // __QUANTKIT_PARAMETER_H__
