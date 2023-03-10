#include "consigne.h"
#include "stdio.h"
FILE *fc;
FILE *verrouC;

   float consigne(float thermostatPrec_f)
   {
   
      float thermostat_f=0;
      float consigne = 0;
      if (access("IHM/.verrouConsigne", F_OK) != -1) {
          //file exists : verrou existant → fichier ouvert
          //message d'erreur si verrou empêche l'ouverture du fichier
          perror("in consigne : Error, verrou exists. cant use consigne.txt\n");
          return thermostatPrec_f;
      }
      else{
          //file dosnt exists : verrou inexistant → fichier fermé
          printf("reading in consigne.txt\n");
          // Création du verrou pour l'ouverture du fichier consigne.txt
          verrouC = fopen("IHM/.verrouConsigne","w");
          fc = fopen("IHM/consigne.txt","r");
          fclose(verrouC);
          fscanf(fc,"%f\n",&consigne); //Lecture de la valeur consigne dans consigne.txt
          fclose(fc);
          remove("IHM/.verrouConsigne");
          //Suppresion du verrou à la fermeture du fichier consigne.txt
          return consigne;
      }

     

   
   }
