#include "visualisationT.h"
FILE *fd;
FILE *verrouD;
void EcrireData(temp_t myTemp){
    if (access("IHM/.verrouData", F_OK) != -1) {
        // file exists
        perror("in VisualT : Error, verrou exists. cant use data.txt");

    } else {
        // file doesn't exist
        printf("writing in data.txt\n");
        verrouD = fopen("IHM/.verrouData","w");
        fd = fopen("IHM/data.txt","w");
        fclose(verrouD);
        fprintf(fd,"%f\n",myTemp.exterieure);
        fprintf(fd,"%f\n",myTemp.interieure);
        fprintf(fd,"%s", 1 ? "true" : "false");
        fclose(fd);

        remove("IHM/.verrouData");
    }


}
void visualisationT(temp_t myTemp){
    EcrireData(myTemp);
}
