.PHONY: clean

.DEFAULT_GOAL := parser

parser: lex.yy.cpp y.tab.cpp symbols.cpp symbols.hpp
	g++ -o $@ y.tab.cpp symbols.cpp -ll


y.tab.cpp: y.y
	bison -y -d $< -o $@ 

lex.yy.cpp: Project1.lex
	flex -o $@ $<

clean:
	rm -f parser lex.yy.cpp y.tab.*