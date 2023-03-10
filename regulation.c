#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "regulation.h"


//Fonction Test de la fonction regulation
float regulationTest(int regul,float consigne,float* tabT, int nT) {
    float cmd=0, error=0, Kp=1, Ki=0.1, Kd=0.1, last_error=0, integrale=0, derive=0;
    int i;
    //regul == 1 pour le TOR et regul == 2 pour le PID
    if (regul == 1) {
        for (i = 0; i < nT; i++) {
            if ((tabT[i] - consigne <= 0)) { //Si temperature intérieur < consigne : ajout de temperature
                cmd = 40; //Puissance de chauffage = 40 si condition respecté
            } else {
                cmd = 0; //Puissance coupée si consigne atteinte
            }
        }
    }
    else if (regul==2){
        float dt=10; //période de temps
        for (i = 1; i < nT; i++){
            //Calcul des différentes variables nécessaires au calcul du PID
            error = consigne - tabT[i];
            derive = (last_error-error)/(dt);
            integrale += (error * dt + (fabs(tabT[i]-tabT[i-1])*dt)/2);
            //PID : P = Kp*error ; I = Ki*intégrale ; D = Kd*dérive
            cmd = Kp*error + Ki*integrale + Kd*derive;
            cmd = fmax(fmin(cmd, 100.0), 0); // limit cmd de +100 à 0
            last_error = error;
        }
    }
    return cmd;
}

float regulation(int regul, float consigne, float T_int, float* integrale, float T_prec, float Error_prec){
    float cmd=0, error, Kp=1, Ki=0.1, Kd=0.1, derive;
    //regul == 1 pour le TOR et regul == 2 pour le PID
    if (regul == 1) {
        if ((T_int - consigne < 0)) { //Si temperature intérieur < consigne : ajout de temperature
            cmd = 40; //Puissance de chauffage = 40 si condition respecté
        } else {
            cmd = 0; //Puissance coupée si consigne atteinte
        }
    }
    else if (regul==2){
        float dt=10; //période de temps (10s)
        // Si la consigne se situe en-dessous de la température intérieur la puissance de chauffage sera égale à 0
        if(consigne<T_int){ //Consigne <= à température intérieur = chauffage éteint
            cmd =0;
            return cmd;
        }
        else{
            error = consigne - T_int;     //Calcul erreur entre consigne demandée et température intérieur
            derive = (error-Error_prec)/dt;  //Calcul de la dérive
            float count = error*dt+(fabs(T_int-T_prec)*dt/2);
            *integrale += count;
            cmd = Kp*error + Ki**integrale + Kd*derive; //Calcul de la puissance de chauffage par P*I*D
            cmd = fmax(fmin(cmd, 100.0), 0); // limit cmd de +100 à 0
        }
    }
    return cmd;
}