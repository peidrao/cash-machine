all:
	clear
	g++ -std=c++11 funcoes.cpp main.cpp -o cash-machine.o
clean: 
	rm *.o
run:
	./cash-machine.o