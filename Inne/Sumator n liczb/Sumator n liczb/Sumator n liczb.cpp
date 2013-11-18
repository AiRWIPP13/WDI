// Sumator n liczb.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//
#include "stdafx.h"

using namespace std;

int rzad(int n);                       //wylicza rzad
int wart_ntej_liczb (int n);           //wartosc n-tej liczby
int r,mnoznik,n;

int main()                            //main()
{
    int wart, ord, suma=0;
    
	cin>>n;

    while (n>=0) {
        ord=rzad(n);                  //r->ord->r w 2 funkcji
        wart=wart_ntej_liczb(n);
        suma+=wart;
        n=n-(wart*ord);
    }
    
	suma--;                           //dlaczego?
	cout<<suma<<"\n";
    cout<<"Zrobione\n";

	system("PAUSE");
    return 0;
}

int rzad(int n)       //wylicza rzad
{
	r=10;
    while (r<=n) {
    r*=10;
    }
    r=r/10;
    return r;
}

int wart_ntej_liczb (int n)          
{
	mnoznik=1;
    while (((n/mnoznik)*r)==1)
	{
		mnoznik++;
    }
    return mnoznik;
}