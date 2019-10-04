#include "dft.h"

vector_t * dft (vector_t & vector_in)
{
	int k, n, largo_in=vector_in.leng();
	vector_t * vector_out = new vector_t(largo_in); //REVISAR ESTE CONSTRUCTOR
	complejo aux{};

	for (k=0; k<largo_in; k++)
	{
		for (n=0, aux.set_re(0), aux.set_im(0); n<largo_in; n++) 
		{
			aux.set_re(aux.re() + (vector_in.valor(n).re())*cos(2*M_PI*n*k/largo_in) - (vector_in.valor(n).im())*sin(2*M_PI*n*k/largo_in));
			aux.set_im(aux.im() + (vector_in.valor(n).re())*sin(2*M_PI*n*k/largo_in) - (vector_in.valor(n).im())*cos(2*M_PI*n*k/largo_in));
		}
		vector_out->append(aux);
	}

	return vector_out;
}

vector_t * idft (vector_t & vector_in)
{
	int n, k, largo_in=vector_in.leng();
	vector_t vector_out(largo_in);
	complejo aux{};

	for (n=0; n<largo_in; n++)
	{
		for (k=0, aux.set_re(0), aux.set_im(0); k<largo_in; k++)
		{
			aux.set_re(aux.re() + (vector_in.valor(k).re())*cos(2*M_PI*k*n/largo_in) + (vector_in.valor(k).im())*sin(2*M_PI*k*n/largo_in));
			aux.set_im(aux.im() + (vector_in.valor(k).re())*sin(2*M_PI*k*n/largo_in) + (vector_in.valor(k).im())*cos(2*M_PI*k*n/largo_in));
		}
		aux.set_re(aux.re()/largo_in);
		aux.set_im(aux.im()/largo_in);
		vector_out.append(aux);
	}

	return new vector_t(vector_out);
}