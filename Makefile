target: all

all: main.o hash.o lex.yy.o
	gcc -o etapa1 main.o hash.o lex.yy.o

test: hashtest.o hash.o 
	gcc -o hashtest hashtest.o hash.o

hashtest.o: hashtest.c
	gcc -c hashtest.c

main.o: main.c
	gcc -c main.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	lex scanner.l


hash.o: hash.c
	gcc -c hash.c


testclean: 
	rm hashtest
	rm hashtest.o
	
clean: 
	rm *.o
	rm etapa1
	rm lex.yy.c
