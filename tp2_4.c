#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5

struct compu {
    int velocidad;//entre 1 y 3 GHz
    int anio;//entre 2015 y 2023
    int cantidad;//entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
};

void presentaListaPC(struct compu PC[]);
void presentaPCMasVieja(struct compu PC[]);
void presentaPCMayorVelocidad(struct compu PC[]);

int main() {

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int i,j;

    srand(time(0));



    struct compu PC[n];//apartado b)
    
    //cargo las n PC
    for(i = 0; i < n; i++) {   

        PC[i].velocidad = (rand() % 3) + 1;
        PC[i].anio = (rand() % 9) + 2015;
        PC[i].cantidad = (rand() % 8) + 1;
        PC[i].tipo_cpu = &tipos[rand() % 6][0]; 
    }

    //apartado C)
    presentaListaPC(PC);
    //apartado D)
    presentaPCMasVieja(PC);
    //apartado E)
    presentaPCMayorVelocidad(PC);
    

    return 0;
}

void presentaListaPC(struct compu PC[]) {

    int i,j;
    
    for(i = 0; i < n; i++) {  

        printf("PC %d - ", i+1);
        printf("velocidad %d GHz\t", PC[i].velocidad);
        printf("anio %d\t", PC[i].anio);
        printf("cantidad %d\t", PC[i].cantidad);
        printf("tipo_cpu ");

        for(j=0; j < 10; j++) {

            printf("%c", *(PC[i].tipo_cpu+j));
        }

        printf("\n\n");
    }
}

void presentaPCMasVieja(struct compu PC[]) {

    int i,min,iMin,j;
    printf("PC mas vieja\n");

    
    for(i = 0; i < n-1; i++) {  

        if (i == 0) { 
            iMin = 0;
            min = PC[iMin].anio;
        }

        if(min >= PC[i+1].anio) { 
            iMin = i+1; 
            min = PC[iMin].anio;
        }        
    }
    
    printf("PC %d - ", iMin+1);
    printf("velocidad %d GHz\t", PC[iMin].velocidad);
    printf("anio %d\t", PC[iMin].anio);
    printf("cantidad %d\t", PC[iMin].cantidad);
    printf("tipo_cpu ");

    for(j=0; j < 10; j++) { printf("%c", *(PC[iMin].tipo_cpu+j)); }

    printf("\n\n");
}


void presentaPCMayorVelocidad(struct compu PC[]) {

    int i,max,iMax,j;
    printf("PC con mayor velocidad\n");

    
    for(i = 0; i < n-1; i++) {  

        if (i == 0) { 
            iMax = 0;
            max = PC[iMax].velocidad;
        }

        if(max <= PC[i+1].velocidad) { 
            iMax = i+1; 
            max = PC[iMax].velocidad;
        }        
    }
    
    printf("PC %d - ", iMax+1);
    printf("velocidad %d GHz\t", PC[iMax].velocidad);
    printf("anio %d\t", PC[iMax].anio);
    printf("cantidad %d\t", PC[iMax].cantidad);
    printf("tipo_cpu ");

    for(j=0; j < 10; j++) { printf("%c", *(PC[iMax].tipo_cpu+j)); }

    printf("\n\n");
}
