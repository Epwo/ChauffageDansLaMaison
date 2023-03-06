#include "visualisationT.h"
FILE *f;
void visualisationT(temp_t myTemp){

}
void EcrireData(temp_t TempInt,temp_t TempExt){
    if (access("IHM/verrouDATA", F_OK) == 0) {
        // file exists
        f = fopen("IHM/data.txt","w");
        fprintf(f,"%d \n",TempExt);
        fprintf(f,"%d\n",TempInt);
        printf("%s", x ? "true" : "false");

    } else {
        // file doesn't exist
        printf("VisualT : Error, verrou exists. cant use data.txt");
    }



}
