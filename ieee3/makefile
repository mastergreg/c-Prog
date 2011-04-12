PROG = prob2.3
all: ${PROG}
${PROG}: ${PROG}.cpp
	g++ ${PROG}.cpp -O3 -Wall -Wextra -o ${PROG} 
clean:
	rm ${PROG} ${PROG}.tar 
tar:
	tar -czvf ${PROG}.tar *
