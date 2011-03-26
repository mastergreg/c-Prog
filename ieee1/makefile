all: prob1
palindrome.o: palindrome.cpp
	g++ -c palindrome.cpp -O3 -Wall -Wextra
prob1: palindrome.o prob1.cpp
	g++ palindrome.o prob1.cpp -O3 -Wall -Wextra -o prob1
clean:
	rm palindrome.o prob1
