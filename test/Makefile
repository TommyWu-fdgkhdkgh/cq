all: test1

test1: test1.o 
	g++ ./test1.o -o test1 -lgmock -lgtest -lpthread  

test1.o: test1.cpp
	g++ -c test1.cpp -I../
	
clean:
	rm -f test1.o test1

