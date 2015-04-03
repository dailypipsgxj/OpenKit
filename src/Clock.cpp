#include <QuantKit/Clock.h>

#include <QuantKit/Framework.h>
#include <QuantKit/Event/Reminder.h>
#include <QuantKit/ReminderCallback.h>

namespace QuantKit {

class ClockPrivate : public QSharedData
{
public:
	Framework m_framework;
	QDateTime m_mode;
	ClockType clockType_0;
	ClockMode m_mode;
	ClockResolution m_resolution;
	long long_0;
	Stopwatch stopwatch_0;
	bool meVefdmJl;
	IEventQueue ieventQueue_0;
	Thread m_thread;

public:
	ClockPrivate(const Framework& framework, ClockType type, bool isStandalone);
	virtual ~ClockPrivate();

public:
	ClockType getClockType_0() const;

	IEventQueue getIeventQueue_0() const;
	long ticks() const;
	QDateTime dateTime() const;
	ClockMode mode() const { return m_mode; }
	void setMode(ClockMode value);
	ClockResolution resolution() const { return m_resolution; }
	void setResolution(ClockResolution value) { m_resolution = value; }
	bool addReminder(const Reminder& reminder);
	bool addReminder(const ReminderCallback& callback, const QDateTime& dateTime, const QVariant& data);
	void clear() { m_mode = DateTime.MinValue; }
	QString getModeAsString();
	void removeReminder(const ReminderCallback& callback, const QDateTime& dateTime)
	{
		((Class63)ieventQueue_0).method_0(callback, dateTime);
	}

	virtual ClockPrivate* clone() Q_DECL_OVERRIDE { return new ClockPrivate(*this); }
//private:
	void method_0();
};

} // namepsace QuantKit


using namespace QuantKit;

ClockPrivate::ClockPrivate(const Framework& framework, ClockType type, bool isStandalone)
	: m_framework(framework)
	, m_mode(DateTime.MinValue)
	, m_mode(ClockMode.Simulation)
	, m_mode(ClockMode.Realtime)
	, m_mode(DateTime.MinValue)
	, m_mode(ClockMode.Simulation)
	, clockType_0(type)
	, long_0(DateTime.Now.Ticks)
	, stopwatch_0(Stopwatch.StartNew())
	, meVefdmJl(isStandalone)
	, m_thread(new Thread(new ThreadStart(method_0())))
{
		if (framework.mode() == FrameworkMode.Realtime)
		{
		}
		else
		{
		}
		if (isStandalone)
		{
			m_thread.Name = "Clock Thread";
			m_thread.IsBackground = true;
			m_thread.Start();
		}
}

ClockPrivate::~ClockPrivate ()
{
}

ClockType getClockType_0() const
{
	return null;
}

IEventQueue getIeventQueue_0() const
{
	return null;
}
long ClockPrivate::ticks() const
{
	if (m_mode != ClockMode.Realtime)
	{
		return m_mode.Ticks;
	}
	if (m_resolution == ClockResolution.Normal)
	{
		return DateTime.Now.Ticks;
	}
	return long_0 + (long)((double)stopwatch_0.ElapsedTicks / (double)Stopwatch.Frequency * 10000000.0);
}

QDateTime ClockPrivate::dateTime() const
{
	if (clockType_0 == ClockType.Exchange)
	{
		return m_mode;
	}
	if (m_mode != ClockMode.Realtime)
	{
		return m_mode;
	}
	if (m_resolution == ClockResolution.Normal)
	{
		return DateTime.Now;
	}
	return new DateTime(long_0 + (long)((double)stopwatch_0.ElapsedTicks / (double)Stopwatch.Frequency * 10000000.0));
}

void ClockPrivate::setMode(ClockMode value)
{
	if (m_mode != value)
	{
		m_mode = value;
		if (m_mode == ClockMode.Simulation)
		{
			m_mode = DateTime.MinValue;
		}
	}
}

bool ClockPrivate::addReminder(const Reminder& reminder)
{
	if (reminder.entryDate() < m_mode)
	{
		Console.WriteLine(string.Concat(new object[]
		{
			"Clock::AddReminder (",
			clockType_0,
			") Can not set reminder to the past. Clock datetime = ",
			m_mode.ToString("dd.MM.yyyy HH:mm:ss.ffff"),
			" Reminder datetime = ",
			reminder.entryDate().ToString("dd.MM.yyyy HH:mm:ss.ffff"),
			" Reminder object = ",
			reminder.data()
		}));
		return false;
	}
	reminder.setClock() = this;
	ieventQueue_0.Enqueue(reminder);
	return true;
}

bool ClockPrivate::addReminder(const ReminderCallback& callback, const QDateTime& dateTime, QVariant data)
{
	return AddReminder(new Reminder(callback, dateTime, data)
	{
		m_clock = this
	});
}

QString ClockPrivate::getModeAsString()
{
	switch (m_mode)
	{
		case ClockMode.Realtime:
			return "Realtime";
		case ClockMode.Simulation:
			return "Simulation";
		default:
			return "Undefined";
	}
}

void ClockPrivate::method_0()
{
	Console.WriteLine(DateTime.Now + " Clock thread started");
	bool flag = false;
	while (true)
	{
		if (m_mode == ClockMode.Realtime)
		{
			if (!ieventQueue_0.IsEmpty())
			{
				long ticks = ieventQueue_0.PeekDateTime().Ticks;
				long ticks2 = m_framework.clock().ticks();
				if (ticks <= ticks2)
				{
					((Reminder)ieventQueue_0.Read()).method_0();
				}
				else
				{
					if (ticks - ticks2 < 15000L)
					{
						flag = true;
					}
				}
			}
			if (flag)
			{
				Thread.SpinWait(1);
			}
			else
			{
				Thread.Sleep(1);
			}
		}
		else
		{
			Thread.Sleep(10);
		}
	}
}


// Pubic API 

Clock::Clock(const Framework& framework, ClockType type, bool isStandalone)
	: d_ptr(new ClockPrivate(framework, type, isStandalone))
{
}

Clock::~Clock()
{
}

Clock::Clock (const Clock &other)
	: d_ptr(other.d_ptr)
{
}

Clock& Clock::operator=(const Clock &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Clock::operator==(const Clock &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

ClockType clockType_0() const
{
	return d_ptr->
	setClockType_0()
}

IEventQueue ieventQueue_0() const
{
	return d_ptr->
	setIeventQueue_0()
}

long Clock::ticks() const
{
	return d_ptr->ticks();
}

QDateTime Clock::dateTime() const
{
	return d_ptr->dateTime();
}

ClockMode Clock::mode() const
{
	return d_ptr->mode();
}

void Clock::setMode(ClockMode value)
{
	d_ptr->setMode(value);
}

ClockResolution Clock::resolution() const
{
	return d_ptr->resolution();
}

void Clock::setResolution(ClockResolution value)
{
	d_ptr->setResolution(value);
}

bool Clock::addReminder(const Reminder& reminder)
{
	return d_ptr->addReminder(reminder);
}

bool Clock::addReminder(const ReminderCallback& callback, const QDateTime& dateTime, QVariant data)
{
	return d_ptr->addReminder(callback, dateTime, data);
}

void Clock::clear()
{
	d_ptr->clear();
}

QString Clock::getModeAsString()
{
	return d_ptr->getModeAsString();
}

void Clock::removeReminder(const ReminderCallback& callback, const QDateTime& dateTime)
{
	d_ptr->removeReminder(callback, dateTime);
}

QDebug operator<<(QDebug dbg, const Clock& clock)
{
	return dbg << clock.toString();
}

