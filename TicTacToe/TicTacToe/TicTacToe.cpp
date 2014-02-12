#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;
//system("cls");
//Sleep (500);
//1-komputer 2-ja
//0 -ruch komp 1-ja

int  m1,m2,m3,           //deklaracja pol gry
	 m4,m5,m6,
	 m7,m8,m9;
	 
int ruch, kto, wygral, wsp; //kto-kolko czy krzyzyk, ruch-czyja kolej 0-ruch komp 1-ja, wygral-1-komputer 2-ja, wsp-wspolrzedna w kwadraciku,przyczynia sie do zwiekszenia losowosci wyboru ruchu przez komputer

bool koniec, nast_ruch; //koniec-ktos wygral i trzeba przerwac gre, nast_ruch- 1 gdy mozna zmienic kolej

void screen (void);
void zeruj_zmienne (void);
void zmiana_ruch (void);
void ustawienia (void);
void kto_wygral (void);
void ruch_moj (void);
void ruch_komp (void);
void podstawienie (int wsp);


int main()
{
	while(1){
		zeruj_zmienne();
		ustawienia();
		while(1){
			kto_wygral();
			screen(); 
			if (koniec == 1){
				koniec = 0;
				break;
			}
			if(!ruch) Sleep (1000);
			if(ruch == 1) ruch_moj();
			else ruch_komp();
			if (nast_ruch == 1) zmiana_ruch();
			else continue;	
		}
		if (wygral == 1) printf ("\nWygral komputer!\n");
		if (wygral == 2) printf ("\nWygral urzytkownik!\n");
		if (wygral == 3) printf ("\nRemis!\n");
		system("pause");
		//czy kontynuowac?
	}

}

void ruch_komp (void){
	while(wsp){
	rand();
	wsp--;
	}
	while(!nast_ruch){
		wsp = rand()%9+1;              //sztuczna inteligencja ;)
		podstawienie (wsp);
	}
}

void podstawienie (int wsp){
	if(!ruch){
		if (wsp == 1 && m1== 0){
		m1=1;
		nast_ruch=1;
		}

		if (wsp == 2 && m2== 0){
			m2=1;
			nast_ruch=1;
		}

		if (wsp == 3 && m3== 0){
			m3=1;
			nast_ruch=1;
		}

		if (wsp == 4 && m4== 0){
			m4=1;
			nast_ruch=1;
		}

		if (wsp == 5 && m5== 0){
			m5=1;
			nast_ruch=1;
		}

		if (wsp == 6 && m6== 0){
			m6=1;
			nast_ruch=1;
		}

		if (wsp == 7 && m7== 0){
			m7=1;
			nast_ruch=1;
		}

		if (wsp == 8 && m8== 0){
			m8=1;
			nast_ruch=1;
		}

		if (wsp == 9 && m9== 0){
			m9=1;
			nast_ruch=1;
		}
	}else{
		if (wsp == 1 && m1== 0){
		m1=2;
		nast_ruch=1;
		}

		if (wsp == 2 && m2== 0){
			m2=2;
			nast_ruch=1;
		}

		if (wsp == 3 && m3== 0){
			m3=2;
			nast_ruch=1;
		}

		if (wsp == 4 && m4== 0){
			m4=2;
			nast_ruch=1;
		}

		if (wsp == 5 && m5== 0){
			m5=2;
			nast_ruch=1;
		}

		if (wsp == 6 && m6== 0){
			m6=2;
			nast_ruch=1;
		}

		if (wsp == 7 && m7== 0){
			m7=2;
			nast_ruch=1;
		}

		if (wsp == 8 && m8== 0){
			m8=2;
			nast_ruch=1;
		}

		if (wsp == 9 && m9== 0){
			m9=2;
			nast_ruch=1;
		}
	}
}

void ruch_moj (void){
	scanf_s("%d",&wsp);                     //_s dla bezpieczeñstwa. Wymagane przez Visual Studio.
	if(wsp < 1 || wsp > 9) return;
	podstawienie (wsp);
}

void kto_wygral (void){
	if(m1 != 0 && m2 != 0 && m3 != 0 && m4 != 0 && m5 != 0 && m6 != 0 && m7 != 0 && m8 != 0 && m9 != 0) wygral=3;

	if(m1==1 && m2==1 && m3==1) wygral=1;
	if(m1==2 && m2==2 && m3==2) wygral=2;

	if(m4==1 && m5==1 && m6==1) wygral=1;
	if(m4==2 && m5==2 && m6==2) wygral=2;

	if(m7==1 && m8==1 && m9==1) wygral=1;
	if(m7==2 && m8==2 && m9==2) wygral=2;

	if(m1==1 && m4==1 && m7==1) wygral=1;
	if(m1==2 && m4==2 && m7==2) wygral=2;

	if(m2==1 && m5==1 && m8==1) wygral=1;
	if(m2==2 && m5==2 && m8==2) wygral=2;

	if(m3==1 && m6==1 && m9==1) wygral=1;
	if(m3==2 && m6==2 && m9==2) wygral=2;

	if(m1==1 && m5==1 && m9==1) wygral=1;
	if(m1==2 && m5==2 && m9==2) wygral=2;

	if(m7==1 && m5==1 && m3==1) wygral=1;
	if(m7==2 && m5==2 && m3==2) wygral=2;

	if (wygral == 1 || wygral == 2 || wygral == 3) koniec = 1;
}


void ustawienia (void){                                               //ustawienia rozgrywki
	while(1){                                                         // wybor figury (o/x)
		system ("cls");
		printf ("Grasz jako: (0 - Kolko, 1 - Krzyzyk)\n");
		scanf_s("%d",&kto);
		if (kto == 0 || kto == 1) {
			break;
		}
		else continue;
	}
	while(1){                                                          //wybor uzytkownika rozpoczynajacego gre
		system ("cls");
		printf ("Kto rozpoczyna? (0 - Komputer, 1 - Ty)\n");
		scanf_s("%d",&ruch);
		if (ruch == 0 || ruch == 1) {
			break;
		}
		else continue;
	}
	while(!ruch){                                                      //losowanie
		system ("cls");
		printf ("Wybierz losowa liczbe od 0 do 1000:\n");
		scanf_s("%d",&wsp);
		if (wsp < 0 || wsp > 1000) {
			continue;
		}
		else break;
	}
}

void zmiana_ruch (void){
	nast_ruch = 0;
	if(ruch) ruch=0;
	else ruch=1;
}

void zeruj_zmienne (void){
	m1=0,m2=0,m3=0,
	m4=0,m5=0,m6=0,
	m7=0,m8=0,m9=0;
	wygral = 0;
}

void screen (void)
{
	system ("cls");
	printf("GRA KOLKO I KZYZYK (created by Dariusz Makarewicz)\n\n");

	printf("Graj jako: ");
	if(kto) printf("krzyzyk\n");
	else printf("kolko\n");

	printf("\n-------\n");

	printf("|");

	if (m1 != 1 && m1 != 2)  printf(" "); 
	else {
			if (kto){
				if(m1 == 1) printf("O");
				else if (m1 == 2) printf("X");
			} else {
				if(m1 == 1) printf("X");
				else if (m1 == 2) printf("O");
				}
		}

	printf("|");

	if (m2 != 1 && m2 != 2)  printf(" "); 
	else {
			if (kto){
				if(m2 == 1) printf("O");
				else if (m2 == 2) printf("X");
			} else {
				if(m2 == 1) printf("X");
				else if (m2 == 2) printf("O");
				}
		}

	printf("|");

	if (m3 != 1 && m3 != 2)  printf(" "); 
	else {
			if (kto){
				if(m3 == 1) printf("O");
				else if (m3 == 2) printf("X");
			} else {
				if(m3 == 1) printf("X");
				else if (m3 == 2) printf("O");
				}
		}

	printf("|\n");

	
	printf("-------\n");

	
	printf("|");

	if (m4 != 1 && m4 != 2)  printf(" "); 
	else {
			if (kto){
				if(m4 == 1) printf("O");
				else if (m4 == 2) printf("X");
			} else {
				if(m4 == 1) printf("X");
				else if (m4 == 2) printf("O");
				}
		}

	printf("|");

	if (m5 != 1 && m5 != 2)  printf(" "); 
	else {
			if (kto){
				if(m5 == 1) printf("O");
				else if (m5 == 2) printf("X");
			} else {
				if(m5 == 1) printf("X");
				else if (m5 == 2) printf("O");
				}
		}

	printf("|");

	if (m6 != 1 && m6 != 2)  printf(" "); 
	else {
			if (kto){
				if(m6 == 1) printf("O");
				else if (m6 == 2) printf("X");
			} else {
				if(m6 == 1) printf("X");
				else if (m6 == 2) printf("O");
				}
		}

	printf("|\n");

	printf("-------\n");

	printf("|");

	if (m7 != 1 && m7 != 2)  printf(" "); 
	else {
			if (kto){
				if(m7 == 1) printf("O");
				else if (m7 == 2) printf("X");
			} else {
				if(m7 == 1) printf("X");
				else if (m7 == 2) printf("O");
				}
		}

	printf("|");

	if (m8 != 1 && m8 != 2)  printf(" "); 
	else {
			if (kto){
				if(m8 == 1) printf("O");
				else if (m8 == 2) printf("X");
			} else {
				if(m8 == 1) printf("X");
				else if (m8 == 2) printf("O");
				}
		}

	printf("|");

	if (m9 != 1 && m9 != 2)  printf(" "); 
	else {
			if (kto){
				if(m9 == 1) printf("O");
				else if (m9 == 2) printf("X");
			} else {
				if(m9 == 1) printf("X");
				else if (m9 == 2) printf("O");
				}
		}

	printf("|\n");

	printf("-------\n\n");

	if (ruch && !koniec){
		printf("Twoj ruch:\n\n");
		printf("|1|2|3|\n");
		printf("|4|5|6|\n");
		printf("|7|8|9|\n");
	}
	if(!ruch && !koniec){
		printf("Komputer...\n\n");

	}
}