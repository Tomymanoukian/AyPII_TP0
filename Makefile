objects = complejo.o vector_t.o dft.o main.o

main.o : main.cpp complejo.o vector_t.o dft.o
	g++ -Wall -c main.cpp

dft.o : dft.cpp dft.h vector_t.o complejo.o
	g++ -Wall -c dft.cpp

complejo.o : complejo.cpp complejo.h
	g++ -Wall -c complejo.cpp

vector_t.o : vector_t.cpp vector_t.h complejo.o
	g++ -Wall -c vector_t.cpp


test-dft: $(objects)
	g++ -Wall -c test_dft.cpp
	g++ -Wall -o test_dft test_dft.o $(objects)

#Empieza la ejecución de la prueba y compara los archivos
	@./test_dft 
	@echo ""
	-@diff -s -b -w test_dft_in.txt test_dft_out.txt
	@rm $(objects) test_dft.o test_dft

clean:
	@rm *.o