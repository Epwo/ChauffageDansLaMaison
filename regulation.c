    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include "regulation.h"


    float regulationTest(int regul,float consigne,float* tabT, int nT) {
        float cmd=0, error=0, Kp=1, Ki=0.1, Kd=0.1, last_error=0, integrale=0, derive=0;
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
        else if (regul==2){
            float dt=10; //période de temps
            float precision =300;
            for (i = 1; i < nT; i++){
                error = consigne - tabT[i];
                derive = (last_error-error)/(dt);
                integrale += (error * dt + (fabs(tabT[i]-tabT[i-1])*dt)/2);
                cmd = Kp*error + Ki*integrale + Kd*derive;
                cmd = fmax(fmin(cmd, 100.0), 0); // limit cmd de +100 à 0
                last_error = error;
            }
        }
        return cmd;
    }

    
  
