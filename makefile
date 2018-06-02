all: gen

parser.tab.c parser.tab.h:	parser.y
	bison -d parser.y

lex.yy.c: scanner.l parser.tab.h
	flex scanner.l

gen: lex.yy.c parser.tab.c parser.tab.h
	mv lex.yy.c lex.c
	mv parser.tab.c parser.c
	gcc -o gen parser.c

clean:
	rm -rf gen parser.c lex.c parser.tab.h
	rm -rf *.out
	rm -rf *.jasm
	rm -rf *.class