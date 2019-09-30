#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<fstream>

#include "dft.h"

using namespace std;

#define TEST_DFT_FILE_IN "test_dft_in.txt"
#define TEST_DFT_FILE_OUT "test_dft_out.txt"

int main()
{
    ifstream test_file_in;
    ofstream test_file_out;
    string line_readed;

    vector_t test_subject;

    test_file_in.open(TEST_DFT_FILE_IN);
    //Compruebo si hubo error al abrir el archivo
    if(!test_file_in)
    {
        cout << "No se puedo abrir el archivo de prueba: " << TEST_DFT_FILE_IN <<endl;
        return 1;
    }

    test_file_out.open(TEST_DFT_FILE_OUT,ofstream::trunc);
    //Compruebo si hubo error al abrir el archivo/crear
    if(!test_file_out)
    {
        cout << "No se pudo abrir/crear el archivo de salida: " << TEST_DFT_FILE_OUT << endl;
    }

    while(!test_file_in.eof())
    {
        //Leo del archivo una linea y lo paso a un stringstream
        getline(test_file_in, line_readed);

        if(line_readed.empty())
        {
            continue;
        }
        
        line_readed = line_readed.substr(0, line_readed.find('='));
        istringstream line_buffer(line_readed);

        //Paso del stringstream al vector_t
        line_buffer >> test_subject;
        
        //Imprime la primer parte
        test_file_out << line_readed << " = " << test_subject << endl;

        test_subject.clean(); //Limpio el vector
        line_readed.clear(); //Limpio el string
    }
    

    test_file_in.close();
    test_file_out.close();
}