#include "visualisationT.h"
FILE *f;
void EcrireData(temp_t myTemp){
    if (access("IHM/verrouDATA", F_OK) == 0) {
        // file exists
        printf("writing in data.txt\n");
        f = fopen("IHM/data.txt","w");
        fprintf(f,"%f\n",myTemp.exterieure);
        printf("%f",myTemp.exterieure);
        fprintf(f,"%f\n",myTemp.interieure);
        fprintf("%s", 1 ? "true" : "false");

    } else {
        // file doesn't exist
        printf("VisualT : Error, verrou exists. cant use data.txt");
    }


}
void visualisationT(temp_t myTemp){
    printf("salut\n");
    EcrireData(myTemp);
}
