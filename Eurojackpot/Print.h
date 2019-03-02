#ifndef PRINT_H
#define PRINT_H

#include "DEFS.h"


void PrintResults( int* pNums50, int* pNums10, Player** pDraws, int nDrawsNo );//mozna zaszyc w wyniki.txt plik wynikowy- bedzie wyslany
//nazwisko imie, funkcja drukujaca plec, funkcja drukujaca date, numer bankowy pelny rozdzielony spacjami
//rozdzielenie minusami
//wszystkie zaklady
//tak kazda osobe
//a na koncu statystyki tych liczb- ile razy wystapilo, kada liczba na dwoch pozycjach
// mam zdjecie na telefonie 27.11.2018r.
void PrintSex( FILE* fout, Player* p );	   //bedze pisac do pliku wyjsciowego na podstawie gracza
// czy facet czy kobieta
void PrintDate( FILE* fout, Player* p );//do pliku wyjsciowego bedzie drukowac do gracza p date postaci *FEMALE*
void PrintBets( FILE* fout, Bets* pBets );//
void PrintNumber( FILE* fout, const char*, int );

//void HeapCheck();//wykopiowac j¹ z helpow. nie pisac _heapchk() -poszukac w helpie check heap status
// potrzeba do sprawdzenia po wyczyszczeniu wszystkiego czy sterta pamieci jest wolna
//void CalcStat( int* pNums50, int pNums10, Player** pDraws, int nDrawsNo );	//ilosci wystapien wszystkich liczb w zakladach od 1 do 50
//oraz wszystkich liczb w zakladach od 1 do 10 (oddzielnie!!!)
//void Sort( Player** pDraws, int nDrawsNo );//ma posortowaæ wed³ug nazwisk w pierwszej
//kolejnosci a w drugiej kolejnosci wedlug imion, napisac funkcje porownujaca, wziac pod uwage
//duze male litery, zalozyc ze nie ma polskich liter
// mozna wykorzystac funkcje biblioteczna
// przydzielic pamiec na dwa lancuchy znakowe, wkopiowac
// zamiana malej na duze, porownac
//zwolnic pamiec


#endif