#ifndef __QUANTKIT_LEVEL2UPDATE_H__
#define __QUANTKIT_LEVEL2UPDATE_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class Level2UpdatePrivate;

class Level2;

class QUANTKIT_EXPORT Level2Update Q_DECL_FINAL : public DataObject
{
public:
	Level2Update();
	Level2Update(const QDateTime& dateTime, unsigned char providerId, int instrumentId, const Level2& entries);
	~Level2Update();

public:
	unsigned char byte_0() const;
	void setByte_0(unsigned char value);

	int int_0() const;
	void setInt_0(int value);
	Level2 entries() const;

private:
	QK_DECLARE_PRIVATE(Level2Update)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Level2Update)

#endif // __QUANTKIT_LEVEL2UPDATE_H__
