#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

#include "main.h"
#include "cmdline.h"
#include "complejo.h"
#include "vector_t.h"
#include "dft.h"

using namespace std;

option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "m", "method", "-", opt_method, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

std::istream *iss=0;	// Input Stream (clase para manejo de los flujos de entrada)
std::ostream *oss=0;	// Output Stream (clase para manejo de los flujos de salida)
std::fstream ifs; 		// Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos)
std::fstream ofs;		// Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)
type_method method;

int main (int argc, char * const argv[])
{
	vector_t vec_in; 
	vector_t vec_out;
	vector_t (*funcionFourier)(vector_t &);

	cmdline cmdl(options);
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline

	//Selecciona cual es el metodo a usar
	if(method == METHOD_DFT)
		funcionFourier = dft;
	else
		funcionFourier = idft;

	while(!iss->eof()){

		if(!(*iss >> vec_in)){

			*oss << MSJ_ERR_VEC_CORRPUTO << endl;

			if(iss -> eof()){
				break;
			}

			iss->clear(ios::goodbit); 
			vec_in.clean();
			vec_out.clean();
			
			continue;
		}

		vec_out = funcionFourier(vec_in);

		*oss << vec_out << endl;

		vec_in.clean();
		vec_out.clean();
	}
	

	if(ifs.is_open())
		ifs.close();

	if(ofs.is_open())
		ofs.close();

	return 0;
}
