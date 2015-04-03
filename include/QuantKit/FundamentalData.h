#ifndef __QUANTKIT_FUNDAMENTALDATA_H__
#define __QUANTKIT_FUNDAMENTALDATA_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class FundamentalDataPrivate;

class QUANTKIT_EXPORT FundamentalData
{
public:
	FundamentalData();
	~FundamentalData();

	FundamentalData(const FundamentalData &other);
	FundamentalData& operator=(const FundamentalData &other);
	bool operator==(const FundamentalData &other) const;
	inline bool operator!=(const FundamentalData &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<FundamentalDataPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const FundamentalData& fundamentaldata);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const FundamentalData& fundamentaldata);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FundamentalData)

#endif // __QUANTKIT_FUNDAMENTALDATA_H__
