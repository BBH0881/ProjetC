
# règle implicite
%: %.c
	gcc -Wall -o $@ $@.c  
all : libmylib.a

libmylib.a:load.o loadaf.o loadf.o search.o afficher.o lecture.o
	ar -rs libmylib.a load.o loadaf.o loadf.o search.o afficher.o lecture.o

load.o : load.c mylib.h
	gcc -Wall -c load.c

loadaf.o : loadaf.c mylib.h
	gcc -Wall -c loadaf.c

loadf.o : loadf.c mylib.h
	gcc -Wall -c loadf.c

search.o : search.c mylib.h
	gcc -Wall -c search.c

lecture.o : lecture.c mylib.h
	gcc -Wall -c lecture.c

afficher.o : afficher.c mylib.h
	gcc -Wall -c afficher.c

clean :
	rm -rf *.o *.txt projetc2

archive :
	tar -zcvf projetC.tar.gz *.c *.conf *.h *.help Makefile