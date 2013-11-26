#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void) {
int a;
int liczba = 0;
int i;
int tablica[liczba];
int b = 0;

printf ("Podaj liczbê losowanych liczb: ");
scanf ("%d", &liczba);
srand(time(0));
do 
{
a=rand()%10;
tablica[b]=a;
b=b+1;
} 
while(a!=liczba);

for (i=0; i<liczba; ++i) 
{
printf ("Element numer %d = %d\n", i, tablica[i]);
}
return 0;
}