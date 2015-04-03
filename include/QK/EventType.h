#ifndef __QUANTKIT_EVENTTYPE_H__
#define __QUANTKIT_EVENTTYPE_H__

#include <QuantKit/quantkit_global.h>

namespace QuantKit {

class QUANTKIT_EXPORT EventType
{
public:
	static const unsigned char Event = 0;
	static const unsigned char DataObject = 0;
	static const unsigned char Tick = 1;
	static const unsigned char Bid = 2;
	static const unsigned char Ask = 3;
	static const unsigned char Trade = 4;
	static const unsigned char Quote = 5;
	static const unsigned char Bar = 6;
	static const unsigned char Level2 = 7;
	static const unsigned char Level2Snapshot = 8;
	static const unsigned char Level2Update = 9;
	static const unsigned char Fill = 10;
	static const unsigned char TimeSeriesItem = 11;
	static const unsigned char Order = 12;
	static const unsigned char ExecutionReport = 13;
	static const unsigned char ExecutionCommand = 14;
	static const unsigned char Reminder = 15;
	static const unsigned char StrategyEvent = 16;
	static const unsigned char Text = 17;
	static const unsigned char DataSeries = 18;
	static const unsigned char FieldList = 19;
	static const unsigned char StrategyStatus = 20;
	static const unsigned char ProviderError = 21;
	static const unsigned char Fundamental = 22;
	static const unsigned char News = 23;
	static const unsigned char ObjectTable = 24;
	static const unsigned char Position = 25;
	static const unsigned char Portfolio = 26;
	static const unsigned char Group = 50;
	static const unsigned char GroupUpdate = 51;
	static const unsigned char GroupEvent = 52;
	static const unsigned char ResponseEvent = 60;
	static const unsigned char OnFrameworkCleared = 99;
	static const unsigned char OnPositionOpened = 110;
	static const unsigned char OnPositionClosed = 111;
	static const unsigned char OnPositionChanged = 112;
	static const unsigned char OnFill = 113;
	static const unsigned char OnTransaction = 114;
	static const unsigned char OnExecutionCommand = 115;
	static const unsigned char OnExecutionReport = 116;
	static const unsigned char OnSendOrder = 117;
	static const unsigned char OnPendingNewOrder = 118;
	static const unsigned char OnNewOrder = 119;
	static const unsigned char OnOrderStatusChanged = 120;
	static const unsigned char OnOrderPartiallyFilled = 121;
	static const unsigned char OnOrderFilled = 122;
	static const unsigned char OnOrderReplaced = 123;
	static const unsigned char OnOrderCancelled = 124;
	static const unsigned char OnOrderRejected = 125;
	static const unsigned char OnOrderReplaceRejected = 126;
	static const unsigned char OnOrderDone = 127;
	static const unsigned char OnOrderManagerCleared = 128;
	static const unsigned char OnInstrumentDefinition = 129;
	static const unsigned char OnInstrumentDefintionEnd = 130;
	static const unsigned char OnHistoricalData = 131;
	static const unsigned char OnHistoricalDataEnd = 132;
	static const unsigned char OnPortfolioAdded = 133;
	static const unsigned char OnPortfolioDeleted = 134;
	static const unsigned char OnPortfolioParentChanged = 135;
	static const unsigned char HistoricalData = 136;
	static const unsigned char HistoricalDataEnd = 137;
	static const unsigned char BarSlice = 138;
	static const unsigned char OnStrategyEvent = 139;
	static const unsigned char AccountData = 140;
	static const unsigned char String = 150;
	static const unsigned char Long = 151;
	static const unsigned char Int64 = 151;
	static const unsigned char Int = 152;
	static const unsigned char Int32 = 152;
	static const unsigned char DateTime = 153;
	static const unsigned char Char = 154;
	static const unsigned char Boolean = 155;
	static const unsigned char Color = 156;
	static const unsigned char Byte = 157;
	static const unsigned char Double = 158;
	static const unsigned char Int16 = 159;
	static const unsigned char OnConnect = 201;
	static const unsigned char OnDisconnect = 202;
	static const unsigned char OnSubscribe = 203;
	static const unsigned char OnUnsubscribe = 204;
	static const unsigned char OnQueueOpened = 205;
	static const unsigned char OnQueueClosed = 206;
	static const unsigned char OnEventManagerStarted = 207;
	static const unsigned char OnEventManagerStopped = 208;
	static const unsigned char OnEventManagerPaused = 209;
	static const unsigned char OnEventManagerResumed = 210;
	static const unsigned char OnEventManagerStep = 211;
	static const unsigned char OnUserCommand = 212;
	static const unsigned char Parameter = 213;
	static const unsigned char ParameterList = 214;
	static const unsigned char OnLogin = 215;
	static const unsigned char OnLogout = 216;
	static const unsigned char OnLoggedIn = 217;
	static const unsigned char OnLoggedOut = 218;
	static const unsigned char OnLoginRejected = 219;
	static const unsigned char OnHeartbeat = 220;
	static const unsigned char OnInstrumentAdded = 221;
	static const unsigned char OnInstrumentDeleted = 222;
	static const unsigned char OnProviderAdded = 223;
	static const unsigned char OnProviderRemoved = 224;
	static const unsigned char OnProviderConnected = 225;
	static const unsigned char OnProviderDisconnected = 226;
	static const unsigned char OnProviderStatusChanged = 227;
	static const unsigned char OnSimulatorStart = 228;
	static const unsigned char OnSimulatorStop = 229;
	static const unsigned char OnSimulatorProgress = 230;
	static const unsigned char OpenQuantInfo = 231;
	static const unsigned char QuantBaseInfo = 232;
	static const unsigned char QuantRouterInfo = 233;
	static const unsigned char QuantDataInfo = 234;
	static const unsigned char SolutionStatus = 251;
	static const unsigned char Attribute = 252;
};

} // namespace QuantKit

#endif // __QUANTKIT_EVENTTYPE_H__
