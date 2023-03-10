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
    float Tabf[31];
    Tabf[0]= 10;
	temperature.exterieure = 14.0;
	temperature.interieure = 15.0;
	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialis�e � 0%
	int i=0; // increment de boucle
	float puissance = 0; // puissance de chauffage
    float consigneVal,tempPrec = 0;
    printf("début boucle\n");
	for(i=1;i< 31;i++){
        Tabf[i] = temperature.interieure;
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
        visualisationT(temperature);
        //REVENIR ICI
        consigneVal = consigne(tempPrec);
        puissance = regulationTest(2, consigneVal,Tabf,i);
        visualisationC(puissance);
        sleep(1);
	}
	simDestruct(monSimulateur_ps); // destruction de simulateur

	return EXIT_SUCCESS;
}
