#ifndef VECTOR_T__H
#define VECTOR_T__H

#define VECTOR_DEFAULT_CAPACIDAD_INICIAL 10;
#define VECTOR_DEFAULT_STEP 5

#include <iostream>
#include "complejo.h"

using namespace std;

class vector_t
{
private:
    complejo* p;
    int tam = 0;
    int capacidad = 0;

    void aumentar_cap(int cant);

public:
    vector_t();
    vector_t(int largo);
    ~vector_t();
    

    int leng();
    complejo valor(int pos);
    void append(complejo &valor);
    void swap(complejo val, int pos);
    
    void print();

    vector_t operator+(vector_t &a);
    complejo operator[](int pos);
    bool operator==(vector_t &vec);

    friend istream & operator>>(istream &is, vector_t &v);
    friend ostream & operator<<(ostream &os, vector_t &v);

};

#endif
