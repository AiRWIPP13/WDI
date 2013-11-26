#!/usr/bin/awk -f
BEGIN {FS =";"}
{for (i=1 ; i<=NF ; i++)
{

	if ($i ~ /[0-9]+$/) {
		if ($i > 1000 && n != NR) {
		x = x+1;
		n = NR;
		}
	print "wiersz: " NR " - " $i;
	}
}}
END {print "Wierszy z conajmniej jednym polem wiekszym od 1000 jest : " x;}



//input.txt

Si3mka;1001;testowa;wiadomosc;1;1000;
oddzielona;100;srednikami;1000;6505;
5abc;2000;1504504584;-10002;5080;
10000;test;adwadwadw;2330233

//Output:
wiersz: 1 - 1001
wiersz: 1 - 1
wiersz: 1 - 1000
wiersz: 2 - 100
wiersz: 2 - 1000
wiersz: 2 - 6505
wiersz: 3 - 2000
wiersz: 3 - 1504504584
wiersz: 3 - -10002
wiersz: 3 - 5080
wiersz: 4 - 10000
wiersz: 4 - 2330233
Wierszy z conajmniej jednym polem wiekszym od 1000 jest : 4
