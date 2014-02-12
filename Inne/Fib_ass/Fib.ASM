use32

MOV edx,10	      ;wartoœæ n-tego wyrazu ciagu

MOV eax,0
MOV ebx,1	     ;wynik
MOV ecx,0

CMP edx,2	  ;if n>=2 skocz do fib
JG fib

jeden: MOV ebx,1
       JMP koniec

fib: PUSH eax	       ;petla for(){}
     MOV eax,ebx
     POP ebx
     ADD ebx,eax
     INC ecx	       ;ecx++

     DEC edx
     CMP ecx,edx       ;if(ecx<edx-1
     INC edx
     JL fib

koniec: MOV eax,ebx	 ;przepisanie wartosci ebx do eax







;unsigned int fib(unsigned int edx) {
;    if(edx == 0) return 0;
;    unsigned int a, b;
;    eax = 0; exb = 1;
;    for(unsigned int ecx=0; ecx < edx-1; ecx++) {
;        std::swap(eax, ebx);
;        ebx += eax;
;    }
;    return ebx;
;}