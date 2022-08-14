/*
Renatto Esteban Guzmán Sosa 21646

    Laboratorio 2   Microprocesadores

*/


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int cantDPI = 3;            // cantidad de DPIs definidos
    
    struct identificacion{      //Creacion de la estructura
        string nombre;
        string apellido;
        long cui;
        int ultimoCUI;
        string expira;
    }dpiList[cantDPI];


// Se añaden los valores de los DPI previamente

    dpiList[0].nombre = "Renatto";
    dpiList[0].apellido = "Guzman";
    dpiList[0].cui = 9999999999;
    dpiList[0].ultimoCUI = 9;
    dpiList[0].expira = "2022";

    dpiList[1].nombre = "Rogelio";
    dpiList[1].apellido = "Guzman";
    dpiList[1].cui = 1111111111;
    dpiList[1].ultimoCUI = 1;
    dpiList[1].expira = "2027";

    dpiList[2].nombre = "Kendrick";
    dpiList[2].apellido = "Lamar";
    dpiList[2].cui = 5555555555;
    dpiList[2].ultimoCUI = 5;
    dpiList[2].expira = "2024";

    int listUltimoCUI[cantDPI];     // Lista con los ultimos valores del CUI

    for(int i=0;i<cantDPI;i++){
        listUltimoCUI[i]=dpiList[i].ultimoCUI;
    }

    sort(listUltimoCUI,listUltimoCUI+cantDPI);      // La lista anterior se ordena de forma ascendente 

    cout << "\n\n  D A T O S    D P I s  \n " << endl;



    for(int i=0;i<cantDPI;i++){                     // Se imprimen los DPIs ya ordenados
        for(int j=0;j<cantDPI;j++){
            if(listUltimoCUI[i]==dpiList[j].ultimoCUI){
                cout << "DPI #" << j+1 << endl;
                cout << "Nombre: " << dpiList[j].nombre << "        ";
                cout << "Apellido: " << dpiList[j].apellido << "        ";
                cout << "CUI del documento: " << dpiList[j].cui << "        ";
                cout << "Fecha de expiracion: " << dpiList[j].expira << "\n" << endl;
                dpiList[j].ultimoCUI = -1;
                j = cantDPI;

            }
        }
    }
    return 0;



}