.PHONY: clean run

.DEFAULT_GOAL := compiler

compiler: lex.yy.cpp y.tab.cpp symbols.cpp symbols.hpp
	g++ -o $@ y.tab.cpp symbols.cpp -ll

y.tab.cpp: y.y
	yacc -d -y -v $< -o $@

lex.yy.cpp: Project1.lex
	lex -o $@ $<

clean:
	rm -f compiler lex.yy.cpp y.tab.* y.output

run : compiler
	@echo "=====start====="
	./compiler $(test).st
	./javaa $(test).jasm
	@java $(test)
	@echo "\n=====end====="
