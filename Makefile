
# règle implicite
%: %.c
	gcc -Wall -o $@ $@.c  


load.o : load.c mylib.h
	gcc -c load.c

loadaf.o : loadaf.c mylib.h
	gcc -c loadaf.c

loadf.o : loadf.c mylib.h
	gcc -c loadf.c

search.o : search.c mylib.h
	gcc -c search.c

afficher.o : afficher.c mylib.h
	gcc -c afficher.c

treetest : projetc2_main.o load.o loadaf.o loadf.o search.o afficher.o
	gcc -Werror -o  treetest projetc2_main.o load.o loadaf.o loadf.o search.o	afficher.o -L mylib.h -L tree.conf

projetc2_main.o : projetc2_main.c mylib.h tree.conf
	gcc -c projetc2_main.c	-L mylib.h -L tree.conf

clean :
	rm -rf *.o *.txt projetc2

archive :
	tar -zcvf projetC.tar.gz *.c *.conf *.h *.help Makefile