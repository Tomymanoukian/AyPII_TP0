#include <iostream>
    using namespace std;

#include "vector_t.h"

vector_t::vector_t(){
    
    tam = 10;
    p = new complejo[tam];
}

vector_t::vector_t(int largo){ //tamaño negativo? falla new?

    tam = largo;
    p = new complejo[tam];
}

vector_t::~vector_t(){

    delete[] p;
}

int vector_t::leng(){

    return tam;
}


void vector_t::swap(complejo val, int pos){ 

    if(pos < tam)
        p[pos] = val; //sobrecargar []?

    else{
        aumentar_tam(pos);
        p[pos] = val;
    }
}

void vector_t::aumentar_tam(int cant){

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

void vector_t::print(){

    cout << "{";

    for(int i = 0; i < tam; i++){
        cout << p[i] << ", ";
    }

    cout << "}" << endl;
}