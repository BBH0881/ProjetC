
# règle implicite
%: %.c
	gcc -Wall -o $@ $@.c  
all:treeload treesearch

treeload : treeload.c ./conf/tree.conf
	gcc -o treeload treeload.c -L ./conf/tree.conf -L mylib -l mylib

treesearch : treesearch.c ./conf/tree.conf
	gcc -o treesearch treesearch.c  -L ./conf/tree.conf -L mylib -l mylib

clean :
	rm -rf *.o *.txt 

RAZ :
	rm -rf *.o *.txt treeload treesearch

archive :
	tar -zcvf projetCV2.tar.gz *.c Makefile *.md ./conf/ ./mylib/