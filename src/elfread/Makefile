OBJS=	elfread elfread.exec

all :	$(OBJS)

elfread :	elfread.c
	echo "% gcc -c elfread.c -Wall" > elfread.comp
	gcc -c elfread.c -Wall >> elfread.comp 2>&1
	echo "% gcc elfread.o -Wall -o elfread" >> elfread.comp
	gcc elfread.o -Wall -o elfread >> elfread.comp 2>&1

elfread.exec :	elfread
	echo "% ./elfread" > elfread.exec
	./elfread >> elfread.exec
	echo "% " >> elfread.exec

clean :
	rm -f $(OBJS) *.o *.comp
