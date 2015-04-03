#ifndef __QUANTKIT_BARSLICE_H__
#define __QUANTKIT_BARSLICE_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class BarSlicePrivate;

class QUANTKIT_EXPORT BarSlice Q_DECL_FINAL : public Event
{
public:
	explicit BarSlice(long size);
	~BarSlice();

public:
	long size() const;

private:
	QK_DECLARE_PRIVATE(BarSlice)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BarSlice)

#endif // __QUANTKIT_BARSLICE_H__
