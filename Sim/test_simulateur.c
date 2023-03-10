#include <stdio.h>
#include <stdlib.h>
#include "simulateur.h"
#include "visualisationC.h"
#include "visualisationT.h"
#include "consigne.h"
#include "regulation.h"

int main(){

	temp_t temperature;
	temperature.exterieure = 14.0;
	temperature.interieure = 15.0;
	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialis�e � 0%
	int i=0; // increment de boucle
    float T_prec = 0;
    float Error_prec = 0;
    float* errorSUM;
    errorSUM = malloc(sizeof(float));
    *errorSUM = 0;
	float puissance; // puissance de chauffage
	for(i=0;i< 30;i++){
        puissance = regulation(2, 23, temperature.interieure, errorSUM, T_prec, Error_prec);
        T_prec = temperature.interieure;
        Error_prec = 23-temperature.interieure;
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
        sleep(1);
        printf("\n");
	}
	simDestruct(monSimulateur_ps); // destruction de simulateur

	return EXIT_SUCCESS;
}
