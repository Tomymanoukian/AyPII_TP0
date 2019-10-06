objects_dft = complejo.o vector_t.o dft.o test_dft.o
objects_prog = complejo.o vector_t.o dft.o cmdline.o main.o

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

#prueba para borrar:
prueba: programa $(objects_prog)
	./programa -i "in_file_prueba.txt"
	
#Prueba de la función DFT
test-dft: $(objects_dft)
	g++ -Wall -o test_dft $(objects_dft)

#Empieza la ejecución de la prueba y compara los archivos
	@./test_dft 
	@printf "\n-----Prueba de DFT-----\n\n"
	-@diff -T -s -b -w test_dft_in.txt test_dft_out.txt
	@rm $(objects_dft) test_dft

#Prueba de memoria de la función DFT
test-dft-memory: $(objects_dft)
	g++ -Wall -o test_dft_memory $(objects_dft)
	@printf "\n-----Prueba de memoria del DFT-----\n\n"
	@valgrind --leak-check=yes ./test_dft_memory
	@rm $(objects_dft) test_dft_memory

clean:
	@rm *.o programa