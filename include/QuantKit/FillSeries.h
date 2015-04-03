#ifndef __QUANTKIT_FILLSERIES_H__
#define __QUANTKIT_FILLSERIES_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <IEnumerator>
#include <QDateTime>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/IndexOption.h>

namespace QuantKit {

class FillSeriesPrivate;

class Fill;

class QUANTKIT_EXPORT FillSeries
{
public:
	explicit FillSeries(const QString& name = "");
	~FillSeries();

	FillSeries(const FillSeries &other);
	FillSeries& operator=(const FillSeries &other);
	bool operator==(const FillSeries &other) const;
	inline bool operator!=(const FillSeries &other) const { return !(this->operator==(other));  }
public:
	int count() const;
	Fill min() const;
	Fill max() const;
	Fill item(int index) const;
	void add(const Fill& fill);
	void clear();
	int getIndex(const QDateTime& datetime, IndexOption option);

private:
	QSharedDataPointer<FillSeriesPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const FillSeries& fillseries);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const FillSeries& fillseries);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FillSeries)

#endif // __QUANTKIT_FILLSERIES_H__
