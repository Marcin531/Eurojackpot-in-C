
//Celem dzialania programu jest przeanalizowanie tekstowego pliku wejsciowego, a nastepnie przedrukowanie wynikow do pliku wyjsciowego (wyniki.txt)
//The purpose of this program is to analyze text input file and print results in outputfile (wyniki.txt)

#include "pch.h"
#include "Data.h"
#include "Print.h"

void CalcStat( int* pNums50, int* pNums10, Player** pDraws, int nDrawsNo );
void Sort( Player** pDraws, int nDrawsNo );
void HeapCheck();
int CompareString( const char* string1, const char* string2 );


int main(int argc, char* argv[])
{
	if( argc != 2 )
	{
		perror( "Jako argument podaj nazwe pliku" );
	}
	Player** players = NULL;

	int amountOfPlayers;

	if( !(amountOfPlayers=ReadData( &players, argv[1] )) )
	{
		perror( "AMOUNTOFPLAYERS=0!" );
		return 1;
	}

	int* pTab50 = ( int* ) calloc( LOTTO, sizeof( int ) );
	int* pTab10 = ( int* ) calloc( EXTRALOTTO, sizeof( int ) );
	if( !pTab50 || !pTab10 )
	{
		perror( "ERROR: BAD MEMORY ALLOCATION" );
		return 2;
	}

	Sort( players, amountOfPlayers );
	CalcStat( pTab50, pTab10, players, amountOfPlayers );
	PrintResults( pTab50, pTab10, players, amountOfPlayers );
	
	
	FreeMem( &players,amountOfPlayers );
	HeapCheck();
	return 0;
}


void CalcStat( int* pNums50, int* pNums10, Player** pDraws, int nDrawsNo )
{
	
	int* mainBet = pNums50;
	int* extraBet = pNums10;

	for( int i = 0; i < nDrawsNo; i++ )
	{
		Player *p = pDraws[i];// przesuniecie na kolejnego gracza
		Bets* bets = p->pBet;
		for( int j = 0; j < p->amountOfBets; j++ )
		{
			int* numbers5 = bets->mainBet;
			for( int k = 0; k < MAXBETS; k++ )
			{
				if( ( *numbers5 > LOTTO ) || ( *numbers5 < 1 ) )
				{
					printf( "Liczby poza zakresem zakladu" );
					return;
				}
				mainBet[*numbers5++ - 1]++; // -1 poniewaz konieczne indeksowanie od 0 
		 // w tablicy mainBet zwiekszamy indeks danej cyferki o jeden w przypadku jej wystapienia
			}

			int* numbers2 = bets->extraBet;
			for( int k = 0; k < MAXEXTRABETS; k++ )
			{
				if( ( *numbers2 > EXTRALOTTO ) || *numbers2 < 1 )
				{
					printf( "Liczby poza zakresem zakladu" );
					return;
				}
				extraBet[*numbers2++ - 1]++; // w tablicy extrabet zwiekszamy indeks danej cyferki o jeden w przypadku jej wystapienia
			 // przsuniecie na kolajna cyfre
			}
			bets++;// przesuniecie na kolejny zaklad
		}

	
	}
	

}

void Sort( Player** pDraws, int nDrawsNo )
{
	for( int i = 0; i < nDrawsNo-1; i++ )
	{
		Player* min = pDraws[i];
		int x = i;

		for( int j = i + 1; j < nDrawsNo; j++ )
		{
			if( CompareString( min->name, pDraws[j]->name ) > 0 ) // zwraca wieksza od zera gdy str1>str2
			{
				min = pDraws[j];//niebezp kopiow struktur  gdy str ma skladowe dynamiczne
				x = j;
			}
			if( !strcmp( min->name, pDraws[j]->name ) )
			{
				if( CompareString( min->surname, pDraws[j]->surname ) > 0 ) // zwraca wieksza od zera gdy str1>str2, porownuje imiona gdy nazwiska sa takie same 
				{
					min = pDraws[j];//niebezp kopiow struktur  gdy str ma skladowe dynamiczne
					x = j;
				}
			}
			
		}
		pDraws[x] = pDraws[i];
		pDraws[i] = min;
	}
}

void HeapCheck()
{
	int heapstatus = _heapchk();
	switch( heapstatus )
	{
	case _HEAPOK:
		printf( " OK - heap is fine\n" );
		break;
	case _HEAPEMPTY:
		printf( " OK - heap is empty\n" );
		break;
	case _HEAPBADBEGIN:
		printf( "ERROR - bad start of heap\n" );
		break;
	case _HEAPBADNODE:
		printf( "ERROR - bad node in heap\n" );
		break;
	}
}


int CompareString( const char* string1, const char* string2 )
{
	char* str1 = ( char* )calloc( strlen( string1 )+1, sizeof( char ) );
	char* str2 = ( char* )calloc( strlen( string2 )+1, sizeof( char ) ); // + 1 bo bit zerowy
	
	if( !str1 || !str2 ) // check
	{
		perror( "StrCompareError: allocation error" );
		return 5;
	}

	strcpy( str1, string1 ); // strcpy(wskaŸnik do docelowej tablicy znaków, wskaŸnik do Ÿród³owej tablicy znaków)
	strcpy( str2, string2 ); // strcpy(wskaŸnik do docelowej tablicy znaków, wskaŸnik do Ÿród³owej tablicy znaków)

	_strupr(str1);
	_strupr(str2);//zamiana na wielkie
	int result = strcmp( str1, str2 ); // compare

	free( str1 );
	free( str2 );

	return result;
}