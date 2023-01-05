OBJS=	constructor constructor.exec

all :	$(OBJS)

constructor :	constructor.c
	echo "% gcc constructor.c -Wall -o constructor" > constructor.comp
	gcc constructor.c -Wall -o constructor >> constructor.comp 2>&1

constructor.exec :	constructor
	echo "% ./constructor" > constructor.exec
	./constructor >> constructor.exec
	echo "% " >> constructor.exec

clean :
	rm -f $(OBJS) *.comp
