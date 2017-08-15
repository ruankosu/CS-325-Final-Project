CC = g++
exe = traveling-salesman

$(exe): main.o branch-and-bound.o BNB.o
	$(CC) main.o branch-and-bound.o BNB.o -o $(exe)
main.o: main.cpp
	$(CC) $(flags) -c main.cpp
branch-and-bound.o: branch-and-bound.cpp
	$(CC) $(flags) -c branch-and-bound.cpp
BNB.o: BNB.cpp
	$(CC) $(flags) -c BNB.cpp

clean:
	rm -f a.out $(exe) *.o
