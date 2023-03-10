#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "visualisationC.h"
#include "visualisationT.h"

//je n'arrive pas a réutiliser les memes noms de variables car ils sont "définis dans visualT" malgré que je les free a la fin de prog.
FILE *fd2;
FILE *verrouD2;
float extRead, intRead = 0;

   void visualisationC(float puissance_f){
       int state = 0;
    if(puissance_f >= 5) {
        state = 1;
    }
    else {
        state = 0;
    }
        if (access("IHM/.verrouData", F_OK) != -1) {
            // file exists
            perror("in VisualC : Error, verrou exists. cant use data.txt");

        } else {
            verrouD2 = fopen("IHM/.verrouData","w");
            fd2 = fopen("IHM/data.txt","r+");
            fclose(verrouD2);
            //on lit la val chauffage state dans le fichier data.txt
            fscanf(fd2,"%f\n %f\n %*s\n",&extRead,&intRead);
            //on ouvre en w+ pour tt effacer dans le data.txt
            fd2 = fopen("IHM/data.txt","w+");
            fprintf(fd2,"%f\n %f\n %s\n",extRead,intRead,state ?"true" : "false");

            fclose(fd2);
            remove("IHM/.verrouData"); //On finit par supprimer le verrou pour que le programme puisse fonctionner
        }


   }
