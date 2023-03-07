    #include <stdio.h>
	 #include <stdlib.h>
    #include "regulation.h"
	 
	float regulationTest(int regul,float consigne,float* tabT, int nT) {
        float cmd;
        int i;
        if (regul == 1) {
            for (i = 0; i < nT; i++) {
                if ((tabT[i] - consigne < 0)) { //Si temperature intérieur < consigne : ajout de temperature
                    cmd = 40; //Puissance de chauffage
                    //printf("la temperature pris en compte est : %f\n", tabT[0]);
                } else {
                    cmd = 0; //Puissance coupée si consigne atteinte
                    //printf("la temperature pris en compte est : %f\n", tabT[0]);
                }
            }
        }
        return cmd;
    }
    
  
