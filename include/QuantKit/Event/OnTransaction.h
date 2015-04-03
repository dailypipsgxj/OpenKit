#ifndef __QUANTKIT_ONTRANSACTION_H__
#define __QUANTKIT_ONTRANSACTION_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnTransactionPrivate;

class Transaction;
class Portfolio;

class QUANTKIT_EXPORT OnTransaction Q_DECL_FINAL : public Event
{
public:
	OnTransaction(const Portfolio& portfolio, const Transaction& transaction);
	~OnTransaction();

public:
	Transaction transaction() const;
	Portfolio portfolio() const;

private:
	QK_DECLARE_PRIVATE(OnTransaction)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnTransaction)

#endif // __QUANTKIT_ONTRANSACTION_H__
