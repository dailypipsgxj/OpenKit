#ifndef __QUANTKIT_FUNDAMENTAL_H__
#define __QUANTKIT_FUNDAMENTAL_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QString>
#include <QVariant>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class FundamentalPrivate;

class ObjectTable;

class QUANTKIT_EXPORT Fundamental Q_DECL_FINAL : public DataObject
{
public:
	Fundamental();
	Fundamental(const QDateTime& dateTime, int providerId, int instrumentId);
	~Fundamental();

public:
	int int_0() const;
	void setInt_0(int value);

	int int_1() const;
	void setInt_1(int value);
	QVariant item(unsigned char index) const;
	void setItem(unsigned char index, const QVariant& value);
	QVariant item(const QString& name) const;
	void setItem(const QString& name, const QVariant& value);
	void addField(const QString& name, unsigned char index);

private:
	QK_DECLARE_PRIVATE(Fundamental)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Fundamental)

#endif // __QUANTKIT_FUNDAMENTAL_H__
