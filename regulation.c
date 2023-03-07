    #include <stdio.h>
	 #include <stdlib.h>
    #include "regulation.h"
	 
	float regulationTest(int regul,float consigne,float* tabT, int nT){
		float cmd;
        if((*tabT-consigne<0)){ //Si temperature intérieur < consigne : ajout de temperature
            cmd = 40.0; //Puissance de chauffage
        }
		else{
            cmd = 0;
        }
		return cmd;
	}
    
  
