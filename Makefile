#ronen.chereshn@msmail.ariel.ac.il

HEADERS = AscendingOrder.hpp DescendingOrder.hpp MiddleOutOrder.hpp Order.hpp ReverseOrder.hpp SideCrossOrder.hpp
FLAGS = -g -Wall

main: main.o
	g++ $(FLAGS) -o main main.o

Main: main
	./main

test: Test.o
	g++ $(FLAGS) -o test Test.o
	./test


main.o: main.cpp $(HEADERS)
	g++ $(FLAGS) -c main.cpp

test.o: Test.cpp $(HEADERS)
	g++ $(FLAGS) -c Test.cpp

valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main

valgrind-test: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

clean:
	rm -f *.o main test

.PHONY: Main main test valgrind clean