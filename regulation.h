    #include <stdio.h>
	#include <stdlib.h>
	#include "define.h" 
    
   float regulationTest(int regul,float consigne,float* tabT, int nT);
    float regulation(int regul, float consigne, float T_int, float* integrale, float T_prec, float Error_prec);
