#include "visualisationT.h"
FILE *f;
FILE *verrou;
void EcrireData(temp_t myTemp){
    if (access("IHM/.verrouData", F_OK) != -1) {
        // file exists
        printf("in VisualT : Error, verrou exists. cant use data.txt");

    } else {
        // file doesn't exist
        printf("writing in data.txt\n");
        verrou = fopen("IHM/.verrouData","w");
        f = fopen("IHM/data.txt","w");
        fclose(verrou);
        fprintf(f,"%f\n",myTemp.exterieure);
        printf("%f\n",myTemp.exterieure);
        fprintf(f,"%f\n",myTemp.interieure);
        printf("%f\n",myTemp.interieure);
        fprintf(f,"%s", 1 ? "true" : "false");
        fclose(f);

        remove("IHM/.verrouData");
    }


}
void visualisationT(temp_t myTemp){
    EcrireData(myTemp);
}
