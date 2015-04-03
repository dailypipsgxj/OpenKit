#ifndef __QUANTKIT_NEWSURGENCY_H__
#define __QUANTKIT_NEWSURGENCY_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class NewsUrgencyPrivate;

class QUANTKIT_EXPORT NewsUrgency
{
public:
	NewsUrgency();
	~NewsUrgency();

	NewsUrgency(const NewsUrgency &other);
	NewsUrgency& operator=(const NewsUrgency &other);
	bool operator==(const NewsUrgency &other) const;
	inline bool operator!=(const NewsUrgency &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<NewsUrgencyPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const NewsUrgency& newsurgency);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const NewsUrgency& newsurgency);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::NewsUrgency)

#endif // __QUANTKIT_NEWSURGENCY_H__
