#include <QuantKit/OrderManager.h>

#include <QuantKit/Event/Order.h>
#include <QuantKit/Framework.h>
#include "OrderServer_p.h"
#include <QuantKit/Event/ExecutionReport.h>
#include "ExecutionMessage_p.h"
#include <QuantKit/IdArray.h>

namespace QuantKit {

class OrderManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	QList<ExecutionMessage> list_0;
	QList<Order> m_orders;
	IdArray<Order> m_idArray;
	Dictionary<QString,QList<Order>> m_dictionary;
	int int_0;
	OrderServer orderServer_0;

public:
	OrderManagerPrivate(const Framework& framework, const OrderServer& server);
	virtual ~OrderManagerPrivate();

public:
	QList<Order> orders() const { return m_orders; }
	void cancel(const Order& order);
	void clear();
	void dump();
	void load();
	void register(const Order& order);
	void reject(const Order& order)
	{
		order.setStatus() = OrderStatus.Rejected;
	}

	void replace(const Order& order, double price)
	{
		Replace(order, price, order.stopPx(), order.qty());
	}

	void replace(const Order& order, double price, double stopPx, double qty);
	void send(const Order& order);
	virtual OrderManagerPrivate* clone() Q_DECL_OVERRIDE { return new OrderManagerPrivate(*this); }
//private:
	void method_1(const Order& order);
};

} // namepsace QuantKit


using namespace QuantKit;

OrderManagerPrivate::OrderManagerPrivate(const Framework& framework, const OrderServer& server)
	: m_framework(framework)
	, list_0(new QList<ExecutionMessage>())
	, m_orders(new QList<Order>())
	, m_idArray(new IdArray<Order>(100000))
	, m_dictionary(new Dictionary<string, QList<Order>>())
	, int_0(0)
	, orderServer_0(server)
{
}

OrderManagerPrivate::~OrderManagerPrivate ()
{
}

void OrderManagerPrivate::cancel(const Order& order)
{
	if (order.status() == OrderStatus.NotSent)
	{
		throw new ApplicationException("Can not cancel order that is not sent " + order);
	}
	if (order.isDone())
	{
		throw new ApplicationException("Can not cancel order that is already done " + order);
	}
	ExecutionCommand executionCommand = new ExecutionCommand(ExecutionCommandType.Cancel, order);
	executionCommand.setEntryDate() = m_framework.clock().dateTime();
	executionCommand.setOrderId() = order.id();
	executionCommand.setProviderId() = order.providerId();
	executionCommand.setRouteId() = order.routeId();
	executionCommand.setPortfolioId() = order.portfolioId();
	executionCommand.setTransactTime() = order.transactTime();
	executionCommand.setInstrument() = order.instrument();
	executionCommand.setInstrumentId() = order.instrument();
	executionCommand.setProvider() = order.provider();
	executionCommand.setPortfolio() = order.portfolio();
	executionCommand.setSide() = order.side();
	executionCommand.setOrdType() = order.type();
	executionCommand.setTimeInForce() = order.timeInForce();
	executionCommand.setPrice() = order.price();
	executionCommand.setStopPx() = order.stopPx();
	executionCommand.setQty() = order.qty();
	executionCommand.setOCA() = order.isOCA();
	executionCommand.setText() = order.text();
	executionCommand.setAccount() = order.account();
	executionCommand.setClientID() = order.clientID();
	list_0.Add(executionCommand);
	order.OnExecutionCommand(executionCommand);
	m_framework.eventServer().method_0(executionCommand);
	if (orderServer_0 != null)
	{
		orderServer_0.Save(executionCommand);
	}
	order.provider().Send(executionCommand);
}

void OrderManagerPrivate::clear()
{
	list_0.Clear();
	m_orders.Clear();
	m_idArray.Clear();
	m_dictionary.Clear();
	int_0 = 0;
	m_framework.eventServer().method_19();
}

void OrderManagerPrivate::dump()
{
	foreach (Order current in m_orders)
	{
		Console.WriteLine(current);
	}
}

void OrderManagerPrivate::load()
{
	if (orderServer_0 != null)
	{
		orderServer_0.Open();
		orderServer_0.Load();
	}
}

void OrderManagerPrivate::register(const Order& order)
{
	if (order.id() != -1)
	{
		Console.WriteLine("OrderManager::Register Error Order is already registered : id = " + order.id());
		return;
	}
	order.setId() = int_0++;
}

void OrderManagerPrivate::replace(const Order& order, double price, double stopPx, double qty)
{
	if (order.status() == OrderStatus.NotSent)
	{
		throw new ApplicationException("Can not replace order that is not sent " + order);
	}
	if (order.isDone())
	{
		throw new ApplicationException("Can not replace order that is already done " + order);
	}
	ExecutionCommand executionCommand = new ExecutionCommand(ExecutionCommandType.Replace, order);
	executionCommand.setEntryDate() = m_framework.clock().dateTime();
	executionCommand.setId() = order.id();
	executionCommand.setOrderId() = order.id();
	executionCommand.setProviderId() = order.providerId();
	executionCommand.setRouteId() = order.routeId();
	executionCommand.setPortfolioId() = order.portfolioId();
	executionCommand.setTransactTime() = order.transactTime();
	executionCommand.setInstrument() = order.instrument();
	executionCommand.setInstrumentId() = order.instrument();
	executionCommand.setProvider() = order.provider();
	executionCommand.setPortfolio() = order.portfolio();
	executionCommand.setSide() = order.side();
	executionCommand.setOrdType() = order.type();
	executionCommand.setTimeInForce() = order.timeInForce();
	executionCommand.setPrice() = price;
	executionCommand.setStopPx() = stopPx;
	executionCommand.setQty() = qty;
	executionCommand.setOCA() = order.isOCA();
	executionCommand.setText() = order.text();
	executionCommand.setAccount() = order.account();
	executionCommand.setClientID() = order.clientID();
	list_0.Add(executionCommand);
	order.OnExecutionCommand(executionCommand);
	m_framework.eventServer().method_0(executionCommand);
	if (orderServer_0 != null)
	{
		orderServer_0.Save(executionCommand);
	}
	order.provider().Send(executionCommand);
}

void OrderManagerPrivate::send(const Order& order)
{
	if (order.status() != OrderStatus.NotSent)
	{
		throw new ApplicationException("Can not send order that has been already sent " + order);
	}
	m_framework.eventServer().method_3(order);
	if (order.id() == -1)
	{
		Register(order);
	}
	if (order.isOCA())
	{
		List<Order> list;
		m_dictionary.TryGetValue(order.isOCA(), out list);
		if (list == null)
		{
			list = new List<Order>();
			m_dictionary[order.isOCA()] = list;
		}
		list.Add(order);
	}
	m_orders.Add(order);
	m_idArray[order.id()] = order;
	order.setEntryDate() = m_framework.clock().dateTime();
	order.setStatus() = OrderStatus.PendingNew;
	ExecutionCommand executionCommand = new ExecutionCommand(ExecutionCommandType.Send, order);
	executionCommand.setEntryDate() = order.entryDate();
	executionCommand.setId() = order.id();
	executionCommand.setOrderId() = order.id();
	executionCommand.setProviderId() = order.providerId();
	executionCommand.setRouteId() = order.routeId();
	executionCommand.setPortfolioId() = order.portfolioId();
	executionCommand.setTransactTime() = order.transactTime();
	executionCommand.setInstrument() = order.instrument();
	executionCommand.setInstrumentId() = order.instrument();
	executionCommand.setProvider() = order.provider();
	executionCommand.setPortfolio() = order.portfolio();
	executionCommand.setSide() = order.side();
	executionCommand.setOrdType() = order.type();
	executionCommand.setTimeInForce() = order.timeInForce();
	executionCommand.setPrice() = order.price();
	executionCommand.setStopPx() = order.stopPx();
	executionCommand.setQty() = order.qty();
	executionCommand.setOCA() = order.isOCA();
	executionCommand.setText() = order.text();
	executionCommand.setAccount() = order.account();
	executionCommand.setClientID() = order.clientID();
	list_0.Add(executionCommand);
	order.OnExecutionCommand(executionCommand);
	m_framework.eventServer().method_0(executionCommand);
	m_framework.eventServer().method_10(order, true);
	if (orderServer_0 != null)
	{
		orderServer_0.Save(executionCommand);
	}
	order.provider().Send(executionCommand);
}

void OrderManagerPrivate::method_1(const Order& order)
{
	if (!order.isOCA())
	{
		return;
	}
	List<Order> list;
	m_dictionary.TryGetValue(order.OCA(), out list);
	if (list == null)
	{
		return;
	}
	m_dictionary.Remove(order.OCA());
	for (int i = 0; i < list.Count; i++)
	{
		Order order2 = list[i];
		if (order2 != order)
		{
			Cancel(order2);
		}
	}
}


// Pubic API 

OrderManager::OrderManager(const Framework& framework, const OrderServer& server)
	: d_ptr(new OrderManagerPrivate(framework, server))
{
}

OrderManager::~OrderManager()
{
}

OrderManager::OrderManager (const OrderManager &other)
	: d_ptr(other.d_ptr)
{
}

OrderManager& OrderManager::operator=(const OrderManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool OrderManager::operator==(const OrderManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QList<Order> OrderManager::orders() const
{
	return d_ptr->orders();
}

void OrderManager::cancel(const Order& order)
{
	d_ptr->cancel(order);
}

void OrderManager::clear()
{
	d_ptr->clear();
}

void OrderManager::dump()
{
	d_ptr->dump();
}

void OrderManager::load()
{
	d_ptr->load();
}

void OrderManager::register(const Order& order)
{
	d_ptr->register(order);
}

void OrderManager::reject(const Order& order)
{
	d_ptr->reject(order);
}

void OrderManager::replace(const Order& order, double price)
{
	d_ptr->replace(order, price);
}

void OrderManager::replace(const Order& order, double price, double stopPx, double qty)
{
	d_ptr->replace(order, price, stopPx, qty);
}

void OrderManager::send(const Order& order)
{
	d_ptr->send(order);
}

QDebug operator<<(QDebug dbg, const OrderManager& ordermanager)
{
	return dbg << ordermanager.toString();
}

