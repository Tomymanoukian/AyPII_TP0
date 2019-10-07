#include <iostream>
#include <fstream>
    using namespace std;

#include "vector_t.h"
#include "complejo.h"

#define MSJ_ERROR "El vector que se ha intentado transformar estaba corrupto"
#define MAX_DIF 0.00000000000001
#endif

//compara dos archivos de igual nombre pero diferente extención
//se debe ingresar solo el nombre del archivo como argumento

int main(int argc, char const *argv[])
{
    
    ifstream file_out((*argv) + ".out");
    ifstream file_ref((*argv) + ".ref")
    string line_out;
    string line_ref;
    complejo c_out, c_ref;

    if(!file_out.is_open() || !file_ref.is_open()){
        cout << "error al abrir los archivos " << endl;
        return 1;
    }

    while(!archivo.eof()){

        getline(file_out, line_out);
        getline(file_ref, line_ref);

        if(!strcmp(line_out, line_ref)){

            if(strcmp(line_out, MSJ_ERROR) || strcmp(line_ref, MSJ_ERROR)){

                cout << "ERROR:\n" << line_out << "\nEs diferente a:\n" << line_ref << endl;
                return 1;
            }

            istringstream str_line_out(line_out);
            istringstream str_line_ref(line_ref);

            while(str_line_out >> c_out && str_line_ref >> c_ref){

                if(abs(c_out.re() - c_ref.re()) > MAX_DIF || abs(c_out.im() - c_ref.im()) > MAX_DIF){

                    cout << "ERROR:\n" << line_out << "\nEs diferente a:\n" << line_ref << endl;
                    return 1;
                }
            }
        }
    }

    file_out.close();
    file_ref.close();

    return 0;
}