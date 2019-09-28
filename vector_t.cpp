#include <iostream>
    using namespace std;

#include "vector_t.h"

vector_t::vector_t(){
    
    capacidad = VECTOR_DEFAULT_CAPACIDAD_INICIAL;
    
    p = new complejo[capacidad];
}

vector_t::vector_t(int largo){ //tamaño negativo? falla new?

    capacidad = largo;
    p = new complejo[capacidad];
}

vector_t::~vector_t(){

    delete[] p;
}

int vector_t::leng(){

    return tam;
}

complejo vector_t::valor(int pos){ //debe fallar si la posicion no es valida

    return p[pos];
}

vector_t vector_t::operator+(vector_t &a){ //hay que pasarlo por referencia o por copia?

    int longitud = tam + a.leng();

    if(capacidad < longitud){
        this->aumentar_tam(longitud);
    }

    for (int i = 0; i < a.leng(); ++i)
    {
        p[this->leng() + i] = a.p[i]; 
    }

    return *this;
}

complejo vector_t::operator[](int pos){
    return p[pos];
}

bool vector_t::operator==(vector_t &vec){ //hay que pasarlo por referencia o por copia?

    if(tam != vec.tam)
    {
        return false;
    }

    for(int i = 0; i < tam;i++)
    {
        if(!(p[i] == vec.p[i])) //agregar != a complejo
        {
            return false;
        }
    }

    return true;
}

istream & operator>>(istream &is, vector_t &v){ //lee un vector_t de complejos separados por espacios del archivo is

    complejo c;
    char a;

    for(int i = 0; is >> c; i++){

        v.swap(c, i);

        if(!(is >> a) || a == '\n'){
            //cout << "falla 1" << endl; //BORRAR
            break;
        }

        if(a != ' '){
            is.clear(ios::badbit);
            //cout << "falla 2: " << a << endl; //BORRAR
            break;
        }
    }

    return is;
}

ostream & operator<<(ostream &os, vector_t &v){ //probar si funciona

    for (int i = 0; i < v.leng(); ++i)
    {
        os << v.valor(i) << " ";
    }

    return os;
}

void vector_t::swap(complejo val, int pos){ 

    if(pos < capacidad)
        p[pos] = val;

    else{
        aumentar_tam(VECTOR_DEFAULT_STEP);
        p[pos] = val;
    }

    ++tam;
}

void vector_t::aumentar_tam(int cant){

    if(cant > capacidad){

        complejo* aux = new complejo[cant];
        capacidad = cant;

        for (int i = 0; i < cant; i++){
            aux[i] = p[i];
        }

        delete[] p;
        p = aux;
    }
}

void vector_t::print(){ // esta funcion es solo para hacer pruebas. borrar antes de la entrega

    cout << "{";

    for(int i = 0; i < tam; i++){
        cout << p[i] << ", ";
    }

    cout << "}" << endl;
}