.PHONY: clean

.DEFAULT_GOAL := scanner

scanner: lex.yy.c
	cc -o $@ -O lex.yy.c -ll

lex.yy.c: Project1.lex
	lex Project1.lex

clean:
	rm -f scanner lex.yy.c
