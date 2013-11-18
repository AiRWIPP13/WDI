// Sumator n liczb.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//
#include "stdafx.h"

int rzad(int n) {              //wylicza rzad
    int r=10;
    while (r<=n) {
    r*=10;
    }
    r=r/10;
    return r;
}

int wart_ntej_liczb (int n, int r){                 //wartosc n-tej liczby
    int mnoznik=1;
    while ((n/mnoznik*r)==1){
        mnoznik=mnoznik+1;
    }
    return mnoznik;
}


int main()                                //main()
{
    int a, n, wart, ord;
    int suma=0;
    scanf_s("%d", &n);

    while (n==0) {
        ord=rzad(n);                            //r->ord->r w 2 funkcji
        wart=wart_ntej_liczb(n,ord);
        suma+=wart;
        n=n-wart*10^ord;
    }
    
	printf("%d\n",suma);
    printf("Zrobione\n");

	system("PAUSE");
    return 0;
}