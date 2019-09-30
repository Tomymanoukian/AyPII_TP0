#include <iostream>
#include <sstream> 
#include <string>
    
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

void vector_t::aumentar_cap(int cant){

    complejo* aux = new complejo[capacidad + cant];
    capacidad = cant;

    for (int i = 0; i < cant; i++){
        aux[i] = p[i];
    }

    delete[] p;
    p = aux;
}


complejo vector_t::valor(int pos){ //debe fallar si la posicion no es valida

    return p[pos];
}

void vector_t::append(complejo &valor)
{
    if(tam == capacidad)
    {
        aumentar_cap(VECTOR_DEFAULT_STEP);
    }

    p[tam] = valor;
    tam++;
}



void vector_t::swap(complejo &val, int pos){ 

    if(pos < tam)
        p[pos - 1] = val;

    else
    {
        throw "Posición fuera de rango";
    }
}

void vector_t::clean()
{
    tam = 0;
    capacidad = VECTOR_DEFAULT_CAPACIDAD_INICIAL;
    delete [] p;
    p = new complejo[capacidad];
}

void vector_t::print(){ // esta funcion es solo para hacer pruebas. borrar antes de la entrega

    cout << "{";

    for(int i = 0; i < tam; i++){
        cout << p[i] << ", ";
    }

    cout << "}" << endl;
}

vector_t vector_t::operator+(vector_t &a){ //hay que pasarlo por referencia o por copia?

    int longitud = tam + a.leng();

    if(capacidad < longitud){
        this->aumentar_cap(longitud);
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
    string line;

    getline(is, line);
    istringstream stream_line(line);

    while(stream_line >> c){
        v.append(c);
    }

    //En caso de que haya error, cambia estado de is
    if(stream_line.bad())
    {
        is.clear(ios::badbit);
        return is;
    }

    return is;
}

ostream & operator<<(ostream &os, vector_t &v){ //probar si funciona

    for (int i = 0; i < v.leng(); i++)
    {
        os << v.valor(i) << " ";
    }

    return os;
}