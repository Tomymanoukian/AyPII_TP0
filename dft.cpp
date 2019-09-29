#include "dft.h"

vector_t dft (vector_t vector_in)
{
	int k, n, largo_in=vector_in.vector_t::leng();
	vector_t vector_out(largo_in);
	complejo aux{};

	for (k=0; k<largo_in; k++)
	{
		for (n=0, aux.complejo::set_re(0), aux.complejo::set_im(0); n<largo_in; n++) 
		{
			aux.complejo::set_re(aux.complejo::re() + (vector_in.vector_t::valor(n).complejo::re())*cos(2*M_PI*n*k/largo_in) - (vector_in.vector_t::valor(n).complejo::im())*sin(2*M_PI*n*k/largo_in));
			aux.complejo::set_im(aux.complejo::im() + (vector_in.vector_t::valor(n).complejo::re())*sin(2*M_PI*n*k/largo_in) - (vector_in.vector_t::valor(n).complejo::im())*cos(2*M_PI*n*k/largo_in));
		}
		vector_out.vector_t::swap(aux,k);
	}

	return vector_out;
}

vector_t idft (vector_t vector_in)
{
	int n, k, largo_in=vector_in.vector_t::leng();
	vector_t vector_out(largo_in);
	complejo aux{};

	for (n=0; n<largo_in; n++)
	{
		for (k=0, aux.complejo::set_re(0), aux.complejo::set_im(0); k<largo_in; k++)
		{
			aux.complejo::set_re(aux.complejo::re() + (vector_in.vector_t::valor(k).complejo::re())*cos(2*M_PI*k*n/largo_in) + (vector_in.vector_t::valor(k).complejo::im())*sin(2*M_PI*k*n/largo_in));
			aux.complejo::set_im(aux.complejo::im() + (vector_in.vector_t::valor(k).complejo::re())*sin(2*M_PI*k*n/largo_in) + (vector_in.vector_t::valor(k).complejo::im())*cos(2*M_PI*k*n/largo_in));
		}
		aux.complejo::set_re(aux.complejo::re()/largo_in);
		aux.complejo::set_im(aux.complejo::im()/largo_in);
		vector_out.vector_t::swap(aux,n);
	}

	return vector_out;
}