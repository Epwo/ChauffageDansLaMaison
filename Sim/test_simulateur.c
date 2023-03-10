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
    float consigneVal,consignePrec=0;
    float* integrale;
    integrale = malloc(sizeof(float));
    *integrale = 0;
    consigneVal = consigne(T_prec);
	float puissance = 0; // puissance de chauffage
	while(1){
        //On définit consignval en lisant la valeur (consigne.txt) définie par python, grace a la fct consigne
        consigneVal = consigne(T_prec);
        if(consigneVal != consignePrec){
            *integrale = 0; //si la valeur de la consigne change, on recommence a calculer l'intégrale de 0
            //afin d'éviter de biaiser nos valeurs
        }
        puissance = regulation(2, consigneVal, temperature.interieure, integrale, T_prec, Error_prec);
        //on Ecrit les valeurs dans data.txt afin des les visualiser dans python
        visualisationT(temperature);
        T_prec = temperature.interieure;
        Error_prec = consigneVal-temperature.interieure;
        temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
        //on écrit dans data.txt si le voyant doit etre allumé ou non. ( en fct de la puissance)
        visualisationC(puissance);
        consignePrec = consigneVal;
        sleep(1);
        printf("\n");
	}
	simDestruct(monSimulateur_ps); // destruction de simulateur

	return EXIT_SUCCESS;
}
