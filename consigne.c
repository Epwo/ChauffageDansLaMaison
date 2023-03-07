#include "consigne.h"
#include "stdio.h"
FILE *fc;
FILE *verrouC;

   float consigne(float thermostatPrec_f)
   {
   
      float thermostat_f=0;
      float consigne = 0;
      if (access("IHM/.verrouConsigne", F_OK) != -1) {
          //file exists
          perror("in consigne : Error, verrou exists. cant use consigne.txt\n");
          return thermostatPrec_f;
      }
      else{
          //file dosnt exist
          printf("reading in consigne.txt\n");
          verrouC = fopen("IHM/.verrouConsigne","w");
          fc = fopen("IHM/consigne.txt","r");
          fclose(verrouC);
          fscanf(fc,"%f\n",&consigne);

          fclose(fc);
          remove("IHM/.verrouConsigne");
          return consigne;
      }

     

   
   }
