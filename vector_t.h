#ifndef VECTOR_T__H
#define VECTOR_T__H

#define VECTOR_DEFAULT_CAPACIDAD_INICIAL 10;
#define VECTOR_DEFAULT_STEP 5

#endif

#include "complejo.h"


class vector_t
{
private:
    complejo* p;
    int tam;
    int capacidad;
public:
    vector_t();
    vector_t(int largo);
    ~vector_t();
    int leng();
    complejo valor(int pos);
    vector_t operator+(vector_t &a);
    complejo operator[](int pos);
    bool operator==(vector_t &vec);
    friend istream & operator>>(istream &is, vector_t &v);
    void swap(complejo val, int pos);
    void aumentar_tam(int cant);
    void print();
};