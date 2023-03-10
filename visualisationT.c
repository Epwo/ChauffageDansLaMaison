#include "visualisationT.h"


void EcrireData(temp_t myTemp){
    FILE *fd=NULL;
    FILE *verrouD=NULL;
    char State[6];
    //LIRE TRUE ou FALSE pour remettre apres

    if (access("IHM/.verrouData", F_OK) != -1) {
        //file exists : verrou existant → fichier ouvert
        perror("in VisualT : Error, verrou exists. cant use data.txt");
        //message d'erreur si verrou empêche l'ouverture du fichier

    } else {
        //file dosnt exists : verrou inexistant → fichier fermé
        printf("writing in data.txt\n");

        // Création du verrou pour l'ouverture du fichier data.txt
        verrouD = fopen("IHM/.verrouData","w");
        //open data.txt in reading mode to save Chauffage state value
        fd = fopen("IHM/data.txt","r+");

        fclose(verrouD);
        //on lit la val chauffage state
        fscanf(fd,"%*f\n %*f\n %s\n",&State);
        fclose(fd);
        //on ouvre en w+ pour tt effacer dans le data.txt
        fd = fopen("IHM/data.txt","w+");
        fprintf(fd,"%f\n",myTemp.exterieure);
        fprintf(fd,"%f\n",myTemp.interieure);
        fprintf(fd,"%s", State);

        //on ferme tout et retire le verrou une fois nos 3 valeurs écrites dans data
        fclose(fd);
        remove("IHM/.verrouData");

    }


}
void visualisationT(temp_t myTemp){
    EcrireData(myTemp);
}
