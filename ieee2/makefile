PROG = prob2
all: ${PROG}
palindrome.o: palindrome.cpp
	g++ -c palindrome.cpp -O3 -Wall -Wextra
${PROG}: palindrome.o ${PROG}.cpp
	g++ palindrome.o ${PROG}.cpp -O3 -Wall -Wextra -o ${PROG} 
clean:
	rm palindrome.o ${PROG} ${PROG}.tar 
tar:
	tar -czvf ${PROG}.tar *
