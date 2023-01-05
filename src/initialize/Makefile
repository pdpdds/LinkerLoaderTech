OBJS=	initialize initialize.exec

all :	$(OBJS)

initialize :	initialize.c
	echo "% gcc initialize.c -Wall -o initialize" > initialize.comp
	gcc initialize.c -Wall -o initialize >> initialize.comp 2>&1

initialize.exec :	initialize
	echo "% ./initialize" > initialize.exec
	./initialize >> initialize.exec
	echo "% " >> initialize.exec

clean :
	rm -f $(OBJS) *.comp

