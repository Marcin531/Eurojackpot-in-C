#ifndef DATA_H
#define DATA_H

#include "DEFS.h"

int ReadData( Player*** pAllDraws, const char* sfileName );//plik wejsciowy jest przekazany przez parametr, sprawdzic argc
int AllocAddMem( Player*** pTab, int nCurrSize );//realokacja dla zakladow, gdzie podaje aktualny rozmiar tej tablicy
void FreeMem( Player*** pTab, int nDrawsNo ); // zwalniam pamiec podajac ilosc graczyi podstawic NULL'a
int SetSex( Player* p, char c );//ustawia w polu struktury playera wskazywanego przez p na podsatwie znaku odpowiednia wartosc
// typu wyliczeniowego do stuktury Player, zrobic switchem, jesli sie okaze ze jest blad to zwracam 0, a nie to 1, ma pokazac blad
// jak inny znak ale to co bylo zapisane ma byc nadal dostepne
int SetDate( Player* p, int d, int m, int y );	//sprawdzic dzien miesiac i rok czy jest wieksz od 1930 
// jesli te dwie funkcje zwroca zero to nalezy przerwac petle czytajaca
int AllocAddBet( Bets** pTab, int nCurrSize );

#endif
