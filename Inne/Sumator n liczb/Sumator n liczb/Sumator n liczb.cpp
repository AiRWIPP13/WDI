// Sumator n liczb.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//
#include "stdafx.h"

using namespace std;

int rzad(int n);                       //wylicza rzad
int r,n;

int main()                            //main()
{
    int wart, ord, suma=0;
    
	cin>>n;

    while (n>=0) {
        ord=rzad(n);                  //r->ord->r w 2 funkcji
        wart=1;
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
