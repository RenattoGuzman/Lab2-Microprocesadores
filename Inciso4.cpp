/*
Renatto Esteban Guzmán Sosa 21646
    Laboratorio 2   Microprocesadores
*/

#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <cstdint>
using namespace std;



void *sumarArray1(void *iVal){      //Método del Hilo 1
	int subtotal = 0;
	int total = 0;
	int *posX;
	
	cout<<"\n -------------- Hilo 1 --------------  "<<endl;
	
	
	posX = (int*)iVal;
    for(int i=0 ; i<5 ; i++){
        subtotal = subtotal + posX[i];
    }
    total = subtotal;
	
	
    cout<<"\n Subtotal de la primera mitad del array: "<<subtotal<<endl;
	pthread_exit(NULL);
    
}

	
void *sumarArray2(void *iVal){        //Método del hilo 2
	int subtotal = 0;
	int total = 0;
	int *posX;
	
	cout<<"\n -------------- Hilo 2 -------------- "<<endl;
	
	posX = (int*)iVal;
    for(int i=5;i<10;i++){
        subtotal = subtotal + posX[i];
    }
    total = subtotal;
	
    cout<<"\nSubtotal de la segunda mitad del array: "<<subtotal<<endl;
	pthread_exit(NULL);
}




int main(){       //Main que ejecuta ambos hilos y hace la sumatoria total
	int RC;
  int RD;
	int numLista [] = {1,2,3,4,5,6,7,8,9,10};
	int sumaTotal= 0;
	
	pthread_t T1;
	pthread_t T2;
	  
	pthread_attr_t TT1;
	pthread_attr_t TT2;

	pthread_attr_init(&TT1);
	pthread_attr_init(&TT2);
		
	pthread_attr_setdetachstate(&TT1, PTHREAD_CREATE_JOINABLE);
	pthread_attr_setdetachstate(&TT2, PTHREAD_CREATE_JOINABLE);
	
	
	RC = pthread_create(&T1, &TT1, sumarArray1, (void *)numLista);
	RD = pthread_create(&T2, &TT2, sumarArray2, (void *)numLista);
	
	
	for(int i=0;i<10;i++){        //Se realiza la suma total
        sumaTotal = sumaTotal + numLista[i];
    }
	
    cout<<"Total de la sumatoria de todos los elementos del array: "<<sumaTotal<<endl;
		
	    if (RC) {              
	      printf("Error; from pthread_create() es %d\n", RC);
	      exit(-1);
	    }
	
	    RC = pthread_join(T1, NULL);
	    if (RC) {
	      printf("Error; pthread_join() es %d\n", RC);
	      exit(-1);
    	}
    	cout<<RC;
		
	    if (RD) {              
	      printf("Error; pthread_create() es %d\n", RC);
	      exit(-1);
	    }
	
	    RD = pthread_join(T2, NULL);
	    if (RD) {
	      printf("Error; pthread_join() es %d\n", RD);
	      exit(-1);
    	}
	

  	pthread_attr_destroy(&TT1);
  	pthread_attr_destroy(&TT2);
  	pthread_exit(NULL);
	
	return 0;
}
