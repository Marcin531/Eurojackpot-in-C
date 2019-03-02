#include "Print.h"

#define RESULTS "wyniki.txt"

void PrintResults( int* pNums50, int* pNums10, Player** pDraws, int nDrawsNo )
{
	FILE* fout=NULL;
	if( !( fout = fopen( RESULTS, "wt" ) ) ) // RESULTS- nazwa pliku wyjsciowego, jesli nie ma tego pliku to go tworzy
		//"w+" - otwiera plik do nadpisywania i czytania "t" - otwiera plik w trybie tekstowym
		//"w" - otwiera plik do nadpisywania (zamazuje star¹ treœæ) "r+" - otwiera plik do czytania i nadpisywania (aktualizacja)
	{
		fputs( RESULTS, fout );
	}
	for(int i=0;i<nDrawsNo;i++ )
	{
		Player* p = pDraws[i];
		
		fprintf( fout, " %s %s \t\t", p->name, p->surname );
		PrintSex( fout, p );
		PrintDate( fout, p );
		fprintf( fout, "\n" );
		fprintf( fout, " " );
		PrintNumber(fout, p->accoutNumber.swift.bank, BANK );
		fprintf( fout, " " );
		PrintNumber( fout, p->accoutNumber.swift.country,COUNTRY );
		fprintf( fout, " " );
		PrintNumber( fout, p->accoutNumber.swift.localization, LOCALIZATION );
		fprintf( fout, " " );
		PrintNumber( fout, p->accoutNumber.swift.branch, BRANCH);

		fprintf( fout, "     " ); // 5 spacji jak w zalaczonym pliku wynikowym

		PrintNumber( fout, p->accoutNumber.iban.country, NRBCOUNTRY );
		fprintf( fout, " " );
		PrintNumber( fout, p->accoutNumber.iban.nrbdesignfirst, NRBDESIGNFIRST );
		fprintf( fout, " " );
		PrintNumber( fout, p->accoutNumber.iban.accnumber, NRBDESIGNSECOND );
		fprintf( fout, " " );
		PrintNumber( fout, p->accoutNumber.iban.nrcountry, NRBDESIGNTHIRD );

		fprintf( fout, "\n--------------------------------------------------------\n" );
		
		Bets* pBets = p->pBet;

		for( int j = 0; j < p->amountOfBets; j++ )
		{
			PrintBets( fout, pBets++ );
		}
		fprintf( fout, "\n" );
	}

	fprintf( fout, "\n\n\n ======================================= \n" );
	fprintf( fout, "      S T A T I S T I C S \n" );
	fprintf( fout, " ======================================= \n" );
	fprintf( fout, "\n NORMAL BETS " );
	for( int i = 0; i < LOTTO; i++ )
	{
		if( !((i+1) % 10) ) fprintf( fout, "\n" );
		fprintf( fout, "%2d:%2d  ", i+1, *pNums50++ );
	}

	fprintf( fout, "\n\n EXTRA BETS " );
	for( int i = 0; i < EXTRALOTTO; i++ )
	{
		if( !((i+1) % 10) ) fprintf( fout, "\n" );
		fprintf( fout, "%2d:%2d  ", i+1, *pNums10++ );
	}
	// uzyj fputc i fprintf
	fclose( fout );
}

void PrintSex( FILE* fout, Player* p )
{
	switch( p->sex )
	{
	case FEMALE :fprintf( fout, "*Panienka* " ); break;
	case MALE :fprintf( fout, "*Facet* " ); break;
	}
}

void PrintDate( FILE* fout, Player* p )
{
		
		switch( p->BetDate.day ) // 0 - poniedzialek 6 - niedziela
		{
		case MON:fprintf( fout, "Mon, " ); break;
		case TUE:fprintf( fout, "Tue, " ); break;
		case WED:fprintf( fout, "Wed, " ); break;
		case THU:fprintf( fout, "Thu, " ); break;
		case FRI:fprintf( fout, "Fri, " ); break;
		case SAT:fprintf( fout, "Sat, " ); break;
		case SUN:fprintf( fout, "Sun, " ); break;
		}

		fprintf( fout, "%d/", p->BetDate.numberOfDay );

		switch( p->BetDate.month )             
		{
		case JAN: fprintf( fout, "Jan/" ); break;
		case FEB: fprintf( fout, "Feb/" ); break;
		case MAR: fprintf( fout, "Mar/" ); break;
		case APR: fprintf( fout, "Apr/" ); break;
		case MAY: fprintf( fout, "May/" ); break;
		case JUN: fprintf( fout, "Jun/" ); break;
		case JUL: fprintf( fout, "Jul/" ); break;
		case AUG: fprintf( fout, "Aug/" ); break;
		case SEP: fprintf( fout, "Sep/" ); break;
		case OCT: fprintf( fout, "Oct/" ); break;
		case NOV: fprintf( fout, "Nov/" ); break;
		case DEC: fprintf( fout, "Dec/" ); break;
		}
	fprintf( fout, "%4d ", p->BetDate.year );
}

void PrintBets( FILE* fout, Bets* pBets )
{
	Bets* p = pBets;
	int* mainBet = p->mainBet;
	int* extraBet = p->extraBet;

	for( int i = 0; i <  MAXBETS; i++ )
		fprintf( fout, "%2d ", *mainBet++ );
	fprintf( fout, "\t" );
	for( int i = 0; i < MAXEXTRABETS; i++ )
		fprintf( fout, "%2d ", *extraBet++ );
	fprintf( fout, "\n" );
}

void PrintNumber( FILE* fout, const char* str, int nSize )
{
	for( int i = 0; i < nSize; i++ )
		fprintf( fout, "%c", *str++ );
}