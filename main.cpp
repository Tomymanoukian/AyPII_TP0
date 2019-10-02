#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

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
	vector_t prueba{};
	vector_t salida{};

	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente. Ver l�nea 51 cmdline.h
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline

	*iss>>prueba;

	if (method==METHOD_DFT) {
		salida=dft(prueba);
	} else if (method==METHOD_IDFT) {
		salida=idft(prueba);
	}

	*oss<<salida<<endl;

	return 0;
}