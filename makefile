all: parser

parser.tab.c parser.tab.h:	parser.y
	bison -d parser.y

lex.yy.c: scanner.l parser.tab.h
	flex scanner.l

parser: lex.yy.c parser.tab.c parser.tab.h
	mv lex.yy.c lex.c
	mv parser.tab.c parser.c
	gcc -o parser parser.c

clean:
	rm -rf parser parser.c lex.c parser.tab.h dump.out
	rm -rf *.jasm