#include<stdio.h>
#include<stdlib.h>



void horasEminutos (int mnts, int *h, int *m) {
        
        *h = mnts/60;
        *m = mnts%60;
               
}

int main(){

        int mnts = 12012312;
        int horas, minutos;
        
        horasEminutos(mnts,&horas,&minutos); 
        printf("%d horas e %d minutos\n",horas,minutos);      

        return 0;
}
