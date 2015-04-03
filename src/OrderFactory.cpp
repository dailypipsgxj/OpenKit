#include <QuantKit/OrderFactory.h>

#include <QuantKit/Event/Order.h>
#include <QuantKit/Event/ExecutionCommand.h>
#include <QuantKit/Event/ExecutionReport.h>
#include <QuantKit/IdArray.h>

namespace QuantKit {

class OrderFactoryPrivate : public QSharedData
{
public:
	IdArray<Order> m_idArray;

public:
	OrderFactoryPrivate();
	virtual ~OrderFactoryPrivate();

public:
	Order onExecutionCommand(const ExecutionCommand& command);
	Order onExecutionReport(const ExecutionReport& report);
	void reset() { m_idArray.Clear(); }
	virtual OrderFactoryPrivate* clone() Q_DECL_OVERRIDE { return new OrderFactoryPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OrderFactoryPrivate::OrderFactoryPrivate()
	: m_idArray(new IdArray<Order>(1000000))
{
}

OrderFactoryPrivate::~OrderFactoryPrivate ()
{
}

Order OrderFactoryPrivate::onExecutionCommand(const ExecutionCommand& command)
{
	Order order = m_idArray[command.orderId()];
	if (order == null)
	{
		order = new Order();
		m_idArray[command.orderId()] = order;
		order.setEntryDate() = command.entryDate();
		order.setId() = command.id();
		order.setProviderId() = command.providerId();
		order.setPortfolioId() = command.portfolioId();
		order.setTransactTime() = command.transactTime();
		order.setInstrument() = command.instrument();
		order.setProvider() = command.provider();
		order.setPortfolio() = command.portfolio();
		order.setSide() = command.side();
		order.setType() = command.ordType();
		order.setTimeInForce() = command.timeInForce();
		order.setPrice() = command.price();
		order.setStopPx() = command.stopPx();
		order.setQty() = command.qty();
		order.setIsOCA() = command.OCA();
		order.setText() = command.text();
		if (command.type() == ExecutionCommandType.Send)
		{
			order.setStatus() = OrderStatus.PendingNew;
		}
	}
	order.OnExecutionCommand(command);
	return order;
}

Order OrderFactoryPrivate::onExecutionReport(const ExecutionReport& report)
{
	Order order = m_idArray[report.orderId()];
	if (order == null)
	{
		return null;
	}
	report.setOrder() = order;
	order.OnExecutionReport(report);
	return order;
}


// Pubic API 

OrderFactory::OrderFactory()
	: d_ptr(new OrderFactoryPrivate)
{
}

OrderFactory::~OrderFactory()
{
}

OrderFactory::OrderFactory (const OrderFactory &other)
	: d_ptr(other.d_ptr)
{
}

OrderFactory& OrderFactory::operator=(const OrderFactory &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool OrderFactory::operator==(const OrderFactory &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Order OrderFactory::onExecutionCommand(const ExecutionCommand& command)
{
	return d_ptr->onExecutionCommand(command);
}

Order OrderFactory::onExecutionReport(const ExecutionReport& report)
{
	return d_ptr->onExecutionReport(report);
}

void OrderFactory::reset()
{
	d_ptr->reset();
}

QDebug operator<<(QDebug dbg, const OrderFactory& orderfactory)
{
	return dbg << orderfactory.toString();
}

