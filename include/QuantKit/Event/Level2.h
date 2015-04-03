#ifndef __QUANTKIT_LEVEL2_H__
#define __QUANTKIT_LEVEL2_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Tick.h>
#include <QuantKit/Level2Side.h>
#include <QuantKit/Level2UpdateAction.h>

namespace QuantKit {

class Level2Private;

class QUANTKIT_EXPORT Level2 Q_DECL_FINAL : public Tick
{
public:
	Level2();
	Level2(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size, Level2Side side, GEnum0 action, int position);
	~Level2();

public:
	Level2Side side() const;
	void setSide(Level2Side value);
	GEnum0 action() const;
	void setAction(GEnum0 value);
	int position() const;
	void setPosition(int value);

private:
	QK_DECLARE_PRIVATE(Level2)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Level2)

#endif // __QUANTKIT_LEVEL2_H__
