#ifndef __QUANTKIT_PROVIDERERROR_H__
#define __QUANTKIT_PROVIDERERROR_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QDateTime>

#include <QuantKit/DataObject.h>
#include <QuantKit/ProviderErrorType.h>

namespace QuantKit {

class ProviderErrorPrivate;

class QUANTKIT_EXPORT ProviderError Q_DECL_FINAL : public DataObject
{
public:
	ProviderError();
	ProviderError(const QDateTime& dateTime, ProviderErrorType type, unsigned char providerId, const QString& text);
	ProviderError(const QDateTime& dateTime, ProviderErrorType type, unsigned char providerId, int id, int code, const QString& text);
	~ProviderError();

public:
	ProviderErrorType type() const;
	void setType(ProviderErrorType value);
	unsigned char providerId() const;
	void setProviderId(unsigned char value);
	int id() const;
	void setId(int value);
	int code() const;
	void setCode(int value);
	QString text() const;
	void setText(const QString& value);

private:
	QK_DECLARE_PRIVATE(ProviderError)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ProviderError)

#endif // __QUANTKIT_PROVIDERERROR_H__
