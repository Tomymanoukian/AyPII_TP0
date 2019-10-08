#include <iostream>
#include <fstream>
#include <sstream>
    using namespace std;
#include <string>

#include "main.h"
#include "vector_t.h"
#include "complejo.h"

#define MAX_DIF 1e-14


//compara dos archivos de igual nombre pero diferente extención
//se debe ingresar solo el nombre del archivo como argumento

int main(int argc, char const *argv[])
{
    string name_file = argv[1];

    ifstream file_out(name_file + ".out");
    ifstream file_ref(name_file + ".ref");

    string line_out;
    string line_ref;

    complejo c_out, c_ref;
    int i = 1;
    bool good = true;
    bool eof = false;
    bool falla_lectura = false;
    bool linea_corrupta;

    if(!file_out.is_open() || !file_ref.is_open()){
        cout << "error al abrir los archivos " << endl;
        return 1;
    }

    while(!eof && !falla_lectura){

        linea_corrupta = false;

        getline(file_out, line_out);
        getline(file_ref, line_ref);

        if(file_out.eof() || file_ref.eof()){

            eof = true;
            continue;
        }

        if(file_out.bad() || file_ref.bad()){

            cout << "Error al leer el los archivos" << endl;
            falla_lectura = true;
            good = false;
            continue;
        }
 
        if(line_out.compare(line_ref)){

            if(!line_out.compare(MSJ_ERR_VEC_CORRPUTO) || !line_ref.compare(MSJ_ERR_VEC_CORRPUTO)){

                cout << "ERROR en la linea nº " << i << "\n" << line_out << "\nEs diferente a:\n" << line_ref << "\n" << endl;
                i++;
                falla_lectura = true;
                good = false;
                continue;
            }

            istringstream str_line_out(line_out);
            istringstream str_line_ref(line_ref);

            while(str_line_out >> c_out && str_line_ref >> c_ref && !linea_corrupta){ //este loop no para bien

                if(abs(c_out.re() - c_ref.re()) > MAX_DIF || abs(c_out.im() - c_ref.im()) > MAX_DIF){

                    cout << "ERROR en la linea nº " << i << "\n" << line_out << "\nEs diferente a:\n" << line_ref << "\n" << endl;
                    i++;
                    linea_corrupta = true;
                    good = false;
                }
            }
            /*if(str_line_out >> c_out || str_line_ref >> c_ref){
                cout << "ERROR en la linea nº " << i << "\n" << line_out << "\nEs diferente a:\n" << line_ref << "\n" << endl;
                i++;
                good = false;
            }
            if(str_line_out >> c_out) cout <<"hola 1 linea: " << i << endl;
            if(str_line_ref >> c_ref) cout <<"hola 2 linea: " << i << endl;*/
        }
        i++;
    }

    if(!falla_lectura && file_out.eof() != file_ref.eof()){
        cout << "ERROR: faltan lineas en el archivo" << endl;
        good = false;
    }

    file_out.close();
    file_ref.close();

    if(good)
        return 0;

    else
        return 1;
}