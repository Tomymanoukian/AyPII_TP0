#ifndef VECTOR_T__H
#define VECTOR_T__H
#endif

#include "complejo.h"

class vector
{
private:
    complejo* p;
    int tam;
public:
    vector();
    vector(int largo);
    ~vector();
    int leng();
    void swap(complejo val, int pos);
    void aumentar_tam(int cant);
    void print();
};