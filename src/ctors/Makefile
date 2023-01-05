OBJS=	ctors ctors.exec ctors.nm ctors.od

all :	$(OBJS)

ctors :	ctors.c
	echo "% gcc ctors.c -Wall -o ctors" > ctors.comp
	gcc ctors.c -Wall -o ctors >> ctors.comp 2>&1

ctors.exec :	ctors
	echo "% ./ctors" > ctors.exec
	./ctors >> ctors.exec
	echo "% " >> ctors.exec

ctors.nm :	ctors
	echo "% nm ctors" > ctors.nm
	cat ../../ellipsis.txt >> ctors.nm
	nm ctors | grep fp >> ctors.nm
	cat ../../rest.txt >> ctors.nm

ctors.od :	ctors
	echo "% objdump -h ctors" > ctors.od
	objdump -h ctors | head -n 5 >> ctors.od
	cat ../../ellipsis.txt >> ctors.od
	objdump -h ctors | head -n 37 | tail -n 4 >> ctors.od
	cat ../../rest.txt >> ctors.od

clean :
	rm -f $(OBJS) *.comp

