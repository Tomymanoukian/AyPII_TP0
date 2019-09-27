// test_vector.cpp - test de unidad para la clase vector_t.
//se debe ingresar primero el comando y luego los vectores de complejos separados por '|'
//+: prueba operator+
//L: prueba leng

#include <iostream>
    using namespace std;

#include "vector_t.h"

int main(){

    char ch;
    vector_t vec1, vec2;

    while(cin >> ch){

        switch(ch){

            case '+':
                if(cin >> vec1
                    && cin >> ch
                    && ch == '|'
                    && cin >> vec2){

                    cout << vec1 << "+" << vec2 << "=" << vec1 + vec2 << endl;
                }
                else{
                    cout << "error en los argumentos" << endl;
                }
        }
    }
}