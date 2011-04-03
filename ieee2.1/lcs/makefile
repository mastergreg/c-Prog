PROG = lcs 
all: ${PROG}
palindrome.o: palindrome.cpp
	g++ -c palindrome.cpp -O3 -Wall -Wextra
lcslib.o: lcslib.c
	g++ -c lcslib.c -O3 -Wall -Wextra
${PROG}: lcslib.o lcs.cpp 
	g++ lcslib.o lcs.cpp -O3 -Wall -Wextra -o ${PROG} 
clean:
	rm palindrome.o ${PROG} ${PROG}.tar 
tar:
	tar -czvf ${PROG}.tar *
