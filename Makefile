objects_dft = complejo.o vector_t.o dft.o test_dft.o
objects_prog = complejo.o vector_t.o dft.o cmdline.o main.o
objects_diff = complejo.o vector_t.o test_diff.o

programa: $(objects_prog)
	g++ -Wall -g -o programa $(objects_prog)

cmdline.o: cmdline.cpp cmdline.h
	g++ -Wall -g -c cmdline.cpp

complejo.o : complejo.cpp complejo.h
	g++ -Wall -g -c complejo.cpp

vector_t.o : vector_t.cpp vector_t.h complejo.h
	g++ -Wall -g -c vector_t.cpp

dft.o : dft.cpp dft.h vector_t.h complejo.h
	g++ -Wall -g -c dft.cpp

main.o : main.cpp cmdline.h complejo.h vector_t.h dft.h
	g++ -Wall -g -c main.cpp

test_dft.o: test_dft.cpp
	g++ -Wall -g -c test_dft.cpp

test_vector.o : test_vector.cpp
	g++ -Wall -g -c test_vector.cpp

test_diff.o: test_diff.cpp complejo.h vector_t.h
	g++ -Wall -g -c test_diff.cpp

#los archivos de prueba se deben llamar test y un numero
test_programa_dft: programa test_diff.o 
	g++ -Wall -g -o test_diff $(objects_diff)

	@set -e; for t in test_dft?; do 					\
	  ./programa -m "dft" -i $$t -o $$t.out;		\
	  echo Aplicando DFT a $$t;						\
	done

	@set -e; for t in test_dft?; do         					\
	  echo testing: $$t;                			\
	  ./test_diff $$t dft;                  		\
	done
	@echo TEST_DFT OK.

	@set -e; for t in test_idft?; do 					\
	  ./programa -m "idft" -i $$t -o $$t.out;	\
	  echo Aplicando IDFT a $$t.ref;				\
	done

	@set -e; for t in test_idft?; do         					\
	  echo testing: $$t;                			\
	  ./test_diff $$t idft;                  		\
	done
	@echo TEST_IDFT OK.


#prueba para borrar:
prueba: programa
	./programa -m "dft" -i "test1.in" -o "test1.out"

#Prueba de la clase vector_t
test-vector_t: complejo.o vector_t.o test_vector.o
	g++ -Wall -o test_vector_t complejo.o vector_t.o test_vector.o

#Empieza la ejecución de la prueba y compara los achivos
	@./test_vector_t test_vector_t.txt
	@printf "\n-----Prueba de Vector_t-----\n\n"
	-@diff -T -s -b -w test_vector_t.txt out_test_vector_t.txt
	@rm complejo.o vector_t.o test_vector.o test_vector_t


#Prueba de la función DFT
test-dft: $(objects_dft)
	g++ -Wall -o test_dft $(objects_dft)

#Empieza la ejecución de la prueba y compara los archivos
	@./test_dft test_dft.txt  
	@printf "\n-----Prueba de DFT-----\n\n"
	-@diff -T -s -b -w test_dft.txt out_test_dft.txt
	@rm $(objects_dft) test_dft

#Prueba de memoria de la función DFT
test-dft-memory: $(objects_dft)
	g++ -Wall -o test_dft_memory $(objects_dft)
	@printf "\n-----Prueba de memoria del DFT-----\n\n"
	@valgrind --leak-check=yes ./test_dft_memory
	@rm $(objects_dft) test_dft_memory

clean:
	@rm -f *.o *.out programa test_diff