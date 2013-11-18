// Sumator n liczb.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"

int r,mnoznik;

int rzad(int n) {
    r=10;
    while (r>=n) {
    r=r*10;
    }
    r=r/10;
    return r;
}

int wart_ntej_liczb (int n){
    mnoznik=1;
    while ((n/mnoznik*r)==1){
        mnoznik=mnoznik+1;
    }
    return mnoznik;
}

int main()
{
    int a,n,suma,wart;
    suma=0;
    scanf("%d", &n);


    while (n=0) {
        int ord=rzad(n);
        int wart=wart_ntej_liczb(n);
        suma=suma+wart;
        n=n-wart*10^ord;
    }
    printf("%d\n",suma);
    printf("zrobione");
    return 0;
}
;p