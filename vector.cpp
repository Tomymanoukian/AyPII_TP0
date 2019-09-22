#include <iostream>
    using namespace std;

#include "vector.h"

vector::vector(){
    
    tam = 10;
    p = new complejo[tam];
}

vector::vector(int largo){ //tamaño negativo? falla new?

    tam = largo;
    p = new complejo[tam];
}

vector::~vector(){

    delete[] p;
}

int vector::leng(){

    return tam;
}


void vector::swap(complejo val, int pos){ 

    if(pos < tam)
        p[pos] = val; //sobrecargar []?

    else{
        aumentar_tam(pos);
        p[pos] = val;
    }
}

void vector::aumentar_tam(int cant){

    if(cant > tam){

        complejo* aux = new complejo[cant];
        tam = cant;

        for (int i = 0; i < cant; i++){
            aux[i] = p[i];
        }

        delete[] p;
        p = aux;
    }
}

void vector::print(){

    cout << "{";

    for(int i = 0; i < tam; i++){
        cout << p[i] << ", ";
    }

    cout << "}" << endl;
}