OBJS=	edata edata.exec edata.od

all :	$(OBJS)

edata :	edata.c
	echo "% gcc edata.c -Wall -o edata" > edata.comp
	gcc edata.c -Wall -o edata >> edata.comp 2>&1
	echo "% " >> edata.comp

edata.exec :	edata
	echo "% ./edata" > edata.exec
	./edata >> edata.exec
	echo "% " >> edata.exec

edata.od :	edata
	echo "% objdump -h edata" > edata.od
	objdump -h edata | head -n 5 >> edata.od
	cat ../../ellipsis.txt >> edata.od
	objdump -h edata | head -n 29 | tail -n 4 >> edata.od
	cat ../../ellipsis.txt >> edata.od
	objdump -h edata | head -n 43 | tail -n 4 >> edata.od
	cat ../../rest.txt >> edata.od

clean :
	rm -f $(OBJS) *.comp

