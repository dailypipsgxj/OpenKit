#ifndef __QUANTKIT_LEVEL2SNAPSHOT_H__
#define __QUANTKIT_LEVEL2SNAPSHOT_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class Level2SnapshotPrivate;

class Bid;
class Ask;

class QUANTKIT_EXPORT Level2Snapshot Q_DECL_FINAL : public DataObject
{
public:
	Level2Snapshot();
	Level2Snapshot(const QDateTime& dateTime, unsigned char providerId, int instrumentId, const Bid& bids, const Ask& asks);
	~Level2Snapshot();

public:
	unsigned char byte_0() const;
	void setByte_0(unsigned char value);

	int int_0() const;
	void setInt_0(int value);
	Bid bids() const;
	Ask asks() const;

private:
	QK_DECLARE_PRIVATE(Level2Snapshot)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Level2Snapshot)

#endif // __QUANTKIT_LEVEL2SNAPSHOT_H__
