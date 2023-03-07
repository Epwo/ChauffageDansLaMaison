#include "consigne.h"

   float consigne(float thermostatPrec_f)
   {
   
      float thermostat_f=0;
      if (access("IHM/.verrouConsigne", F_OK) != -1) {
          //file exists
          printf("in consigne : Error, verrou exists. cant use consigne.txt");
      }
      else{
          //file dosnt exist


      }
     
      return thermostat_f;
   
   }
