#ifndef __QUANTKIT_CURRENCYID_H__
#define __QUANTKIT_CURRENCYID_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>

namespace QuantKit {

class QUANTKIT_EXPORT CurrencyId
{
public:
	/*
	* return 0 means not found
	*/
    static unsigned char id(const QString &name);

	/*
	* return QString().isEmpty() == true means not found
	*/
    static const QString& name(unsigned char id);

	static const unsigned char AED = 1;
	static const unsigned char AFN = 2;
	static const unsigned char ALL = 3;
	static const unsigned char AMD = 4;
	static const unsigned char ANG = 5;
	static const unsigned char AOA = 6;
	static const unsigned char ARS = 7;
	static const unsigned char AUD = 8;
	static const unsigned char AWG = 9;
	static const unsigned char AZN = 10;
	static const unsigned char BAM = 11;
	static const unsigned char BBD = 12;
	static const unsigned char BDT = 13;
	static const unsigned char BGN = 14;
	static const unsigned char BHD = 15;
	static const unsigned char BIF = 16;
	static const unsigned char BMD = 17;
	static const unsigned char BND = 18;
	static const unsigned char BOB = 19;
	static const unsigned char BRL = 20;
	static const unsigned char BSD = 21;
	static const unsigned char BTN = 22;
	static const unsigned char BWP = 23;
	static const unsigned char BYR = 24;
	static const unsigned char BZD = 25;
	static const unsigned char CAD = 26;
	static const unsigned char CDF = 27;
	static const unsigned char CHF = 28;
	static const unsigned char CLP = 29;
	static const unsigned char CNY = 30;
	static const unsigned char COP = 31;
	static const unsigned char CRC = 32;
	static const unsigned char CUC = 33;
	static const unsigned char CUP = 34;
	static const unsigned char CVE = 35;
	static const unsigned char CZK = 36;
	static const unsigned char DJF = 37;
	static const unsigned char DKK = 38;
	static const unsigned char DOP = 39;
	static const unsigned char DZD = 40;
	static const unsigned char EGP = 41;
	static const unsigned char ERN = 42;
	static const unsigned char ETB = 43;
	static const unsigned char EUR = 44;
	static const unsigned char FJD = 45;
	static const unsigned char FKP = 46;
	static const unsigned char GBP = 47;
	static const unsigned char GEL = 48;
	static const unsigned char GGP = 49;
	static const unsigned char GHS = 50;
	static const unsigned char GIP = 51;
	static const unsigned char GMD = 52;
	static const unsigned char GNF = 53;
	static const unsigned char GTQ = 54;
	static const unsigned char GYD = 55;
	static const unsigned char HKD = 56;
	static const unsigned char HNL = 57;
	static const unsigned char HRK = 58;
	static const unsigned char HTG = 59;
	static const unsigned char HUF = 60;
	static const unsigned char IDR = 61;
	static const unsigned char ILS = 62;
	static const unsigned char IMP = 63;
	static const unsigned char INR = 64;
	static const unsigned char IQD = 65;
	static const unsigned char IRR = 66;
	static const unsigned char ISK = 67;
	static const unsigned char JEP = 68;
	static const unsigned char JMD = 69;
	static const unsigned char JOD = 70;
	static const unsigned char JPY = 71;
	static const unsigned char KES = 72;
	static const unsigned char KGS = 73;
	static const unsigned char KHR = 74;
	static const unsigned char KMF = 75;
	static const unsigned char KPW = 76;
	static const unsigned char KRW = 77;
	static const unsigned char KWD = 78;
	static const unsigned char KYD = 79;
	static const unsigned char KZT = 80;
	static const unsigned char LAK = 81;
	static const unsigned char LBP = 82;
	static const unsigned char LKR = 83;
	static const unsigned char LRD = 84;
	static const unsigned char LSL = 85;
	static const unsigned char LTL = 86;
	static const unsigned char LYD = 87;
	static const unsigned char MAD = 88;
	static const unsigned char MDL = 89;
	static const unsigned char MGA = 90;
	static const unsigned char MKD = 91;
	static const unsigned char MMK = 92;
	static const unsigned char MNT = 93;
	static const unsigned char MOP = 94;
	static const unsigned char MRO = 95;
	static const unsigned char MUR = 96;
	static const unsigned char MVR = 97;
	static const unsigned char MWK = 98;
	static const unsigned char MXN = 99;
	static const unsigned char MYR = 100;
	static const unsigned char MZN = 101;
	static const unsigned char NAD = 102;
	static const unsigned char NGN = 103;
	static const unsigned char NIO = 104;
	static const unsigned char NOK = 105;
	static const unsigned char NPR = 106;
	static const unsigned char NZD = 107;
	static const unsigned char OMR = 108;
	static const unsigned char PAB = 109;
	static const unsigned char PEN = 110;
	static const unsigned char PGK = 111;
	static const unsigned char PHP = 112;
	static const unsigned char PKR = 113;
	static const unsigned char PLN = 114;
	static const unsigned char PYG = 115;
	static const unsigned char QAR = 116;
	static const unsigned char RON = 117;
	static const unsigned char RSD = 118;
	static const unsigned char RUB = 119;
	static const unsigned char RWF = 120;
	static const unsigned char SAR = 121;
	static const unsigned char SBD = 122;
	static const unsigned char SCR = 123;
	static const unsigned char SDG = 124;
	static const unsigned char SEK = 125;
	static const unsigned char SGD = 126;
	static const unsigned char SHP = 127;
	static const unsigned char SLL = 128;
	static const unsigned char SOS = 129;
	static const unsigned char SPL = 130;
	static const unsigned char SRD = 131;
	static const unsigned char STD = 132;
	static const unsigned char SVC = 133;
	static const unsigned char SYP = 134;
	static const unsigned char SZL = 135;
	static const unsigned char THB = 136;
	static const unsigned char TJS = 137;
	static const unsigned char TMT = 138;
	static const unsigned char TND = 139;
	static const unsigned char TOP = 140;
	static const unsigned char TRY = 141;
	static const unsigned char TTD = 142;
	static const unsigned char TVD = 143;
	static const unsigned char TWD = 144;
	static const unsigned char TZS = 145;
	static const unsigned char UAH = 146;
	static const unsigned char UGX = 147;
	static const unsigned char USD = 148;
	static const unsigned char UYU = 149;
	static const unsigned char UZS = 150;
	static const unsigned char VEF = 151;
	static const unsigned char VND = 152;
	static const unsigned char VUV = 153;
	static const unsigned char WST = 154;
	static const unsigned char XAF = 155;
	static const unsigned char XCD = 156;
	static const unsigned char XDR = 157;
	static const unsigned char XOF = 158;
	static const unsigned char XPF = 159;
	static const unsigned char YER = 160;
	static const unsigned char ZAR = 161;
	static const unsigned char ZMW = 162;
	static const unsigned char ZWD = 163;
	static const unsigned char CNH = 201;
};

} // namespace QuantKit

#endif // __QUANTKIT_CURRENCYID_H__
