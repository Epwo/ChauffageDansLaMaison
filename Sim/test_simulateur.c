#include <stdio.h>
#include <stdlib.h>
#include "simulateur.h"
#include "../visualisationC.h"
#include "../visualisationT.h"
#include "../consigne.h"
#include "../regulation.h"
#include "../consigne.h"
#include "../regulation.h"

int main(){

	temp_t temperature;
	temperature.exterieure = 14.0;
	temperature.interieure = 15.0;
	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialis�e � 0%
	int i=0; // increment de boucle
    float T_prec = 0;
    float Error_prec = 0;
    float consigneVal,consignePrec =0;
    float* integrale;
    integrale = malloc(sizeof(float));
    *integrale = 0;
	float puissance = 0; // puissance de chauffage
	while(1){
        consigneVal = consigne(T_prec);
        if(consigneVal != consignePrec){
            *integrale = 0;
        }
        puissance = regulation(2, consigneVal, temperature.interieure, integrale, T_prec, Error_prec);
        visualisationT(temperature);
        T_prec = temperature.interieure;
        Error_prec = consigneVal-temperature.interieure;
        temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
        visualisationC(puissance);
        usleep(800000);
        consignePrec = consigneVal;
        printf("\n");
	}
	simDestruct(monSimulateur_ps); // destruction de simulateur

	return EXIT_SUCCESS;
}
