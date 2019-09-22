#ifndef VECTOR_T__H
#define VECTOR_T__H
#endif

#include "complejo.h"

class vector_t
{
private:
    complejo* p;
    int tam;
public:
    vector_t();
    vector_t(int largo);
    ~vector_t();
    int leng();
    void swap(complejo val, int pos);
    void aumentar_tam(int cant);
    void print();
};