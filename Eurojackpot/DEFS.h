#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <memory.h>
#include <malloc.h>

#define MAXBETS 5
#define MAXEXTRABETS 2
#define ALLOCPLAYER 5
#define ALLOCBET 3
#define MAXNAME 31
#define MAXPESEL 12
#define INTERNATIONAL 29
#define ACCOUNT 12

#define BANK 4
#define COUNTRY 2
#define LOCALIZATION 2
#define BRANCH 3

#define NRBCOUNTRY 2
#define NRBDESIGNFIRST 2
#define NRBDESIGNSECOND 8
#define NRBDESIGNTHIRD 16

#define LOTTO 50
#define EXTRALOTTO 10


typedef enum { MALE, FEMALE } SexType;
typedef enum { MON, TUE, WED, THU, FRI, SAT, SUN } Days;
typedef enum { JAN=1, FEB, MAR=9, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC } Months; // zaczynamy numeracje od 1

typedef struct
{
	Days day;
	Months month;
	int numberOfDay;
	int year;
	//!!!!
}BetDate;


typedef struct
{
	int* mainBet;
	int* extraBet;
}Bets;

typedef struct
{
	 char bank[BANK];
	 char country[COUNTRY];
	 char localization[LOCALIZATION];
	char branch[BRANCH];
} Swift;

typedef struct
{
	char country[NRBCOUNTRY];
	char nrbdesignfirst[NRBDESIGNFIRST];
	char accnumber[NRBDESIGNSECOND];
	char nrcountry[NRBDESIGNTHIRD];
} Iban;

typedef struct
{
	Swift swift;
	Iban iban;
} Account;

typedef struct
{
	char name [MAXNAME];
	char surname [MAXNAME];
	SexType sex;
	char PESEL[MAXPESEL];
	Account accoutNumber;
	int amountOfBets;
	Bets* pBet;
	BetDate BetDate;
}Player;




#endif