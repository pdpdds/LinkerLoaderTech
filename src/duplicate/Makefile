OBJS=	dupmain.o libdup.a \
	duplicate1 duplicate2 duplicate3 duplicate4

all :	$(OBJS)

dupmain.o :	dupmain.c duptest1.c duptest2.c dup1.c dup2.c
	echo "% gcc -c dupmain.c -Wall" > dupmain.o.comp
	gcc -c dupmain.c -Wall >> dupmain.o.comp 2>&1
	echo "% gcc -c duptest1.c -Wall" >> dupmain.o.comp
	gcc -c duptest1.c -Wall >> dupmain.o.comp 2>&1
	echo "% gcc -c duptest2.c -Wall" >> dupmain.o.comp
	gcc -c duptest2.c -Wall >> dupmain.o.comp 2>&1
	echo "% gcc -c dup1.c -Wall" >> dupmain.o.comp
	gcc -c dup1.c -Wall >> dupmain.o.comp 2>&1
	echo "% gcc -c dup2.c -Wall" >> dupmain.o.comp
	gcc -c dup2.c -Wall >> dupmain.o.comp 2>&1
	echo "% " >> dupmain.o.comp

libdup.a :	dupmain.o
	echo "% ar ruc libduptest1.a duptest1.o" > libdup.comp
	ar ruc libduptest1.a duptest1.o >> libdup.comp 2>&1
	echo "% ar ruc libduptest2.a duptest2.o" >> libdup.comp
	ar ruc libduptest2.a duptest2.o >> libdup.comp 2>&1
	echo "% ar ruc libdup1.a dup1.o" >> libdup.comp
	ar ruc libdup1.a dup1.o >> libdup.comp 2>&1
	echo "% ar ruc libdup2.a dup2.o" >> libdup.comp
	ar ruc libdup2.a dup2.o >> libdup.comp 2>&1
	echo "% ar ruc libdup.a dup1.o dup2.o" >> libdup.comp
	ar ruc libdup.a dup1.o dup2.o >> libdup.comp 2>&1
	echo "% " >> libdup.comp

duplicate1 :	libdup.a
	echo "% gcc dupmain.o -lduptest1 -lduptest2 -ldup -L. -o duplicate1 -Wall" > duplicate1.comp
	gcc dupmain.o -lduptest1 -lduptest2 -ldup -L. -o duplicate1 -Wall >> duplicate1.comp 2>&1
	echo "% ./duplicate1" >> duplicate1.comp
	./duplicate1 >> duplicate1.comp

duplicate2 :	libdup.a
	echo "% gcc dupmain.o -lduptest1 -ldup1 -lduptest2 -L. -o duplicate2 -Wall" > duplicate2.comp
	gcc dupmain.o -lduptest1 -ldup1 -lduptest2 -L. -o duplicate2 -Wall >> duplicate2.comp 2>&1
	echo "% ./duplicate2" >> duplicate2.comp
	./duplicate2 >> duplicate2.comp

duplicate3 :	libdup.a
	echo "% gcc dupmain.o -lduptest1 -ldup1 -lduptest2 -ldup2 -L. -o duplicate3 -Wall" > duplicate3.comp
	gcc dupmain.o -lduptest1 -ldup1 -lduptest2 -ldup2 -L. -o duplicate3 -Wall >> duplicate3.comp 2>&1
	echo "% ./duplicate3" >> duplicate3.comp
	./duplicate3 >> duplicate3.comp

duplicate4 :	libdup.a
	echo "% gcc dupmain.o -lduptest1 -ldup2 -ldup1 -lduptest2 -L. -o duplicate4 -Wall" > duplicate4.comp
	gcc dupmain.o -lduptest1 -ldup2 -ldup1 -lduptest2 -L. -o duplicate4 -Wall >> duplicate4.comp 2>&1
	echo "% ./duplicate4" >> duplicate4.comp
	./duplicate4 >> duplicate4.comp

clean :
	rm -f $(OBJS) *.comp *.o *.a
