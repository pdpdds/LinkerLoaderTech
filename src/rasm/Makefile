all :	rasm rasm.o rasm.o.re rasm2.o.re rasm.re rasm.o.ra rasm2.o.ra rasm.ra

rasm :	rasm.o
	echo "% gcc rasm.o rasm2.o -o rasm -Wall" > rasm.comp
	gcc rasm.o rasm2.o -o rasm -Wall >> rasm.comp 2>&1
	echo "% " >> rasm.comp

rasm.o :	rasm.c rasm2.c
	echo "% gcc -c rasm.c -Wall" > rasm.o.comp
	gcc -c rasm.c -Wall >> rasm.o.comp 2>&1
	echo "% gcc -c rasm2.c -Wall" >> rasm.o.comp
	gcc -c rasm2.c -Wall >> rasm.o.comp 2>&1

rasm.o.re :	rasm.o
	echo "% readelf -S -r -s rasm.o" > rasm.o.re
	readelf -S -r -s rasm.o >> rasm.o.re
	echo "% " >> rasm.o.re

rasm2.o.re :	rasm2.o
	echo "% readelf -S -s rasm2.o" > rasm2.o.re
	readelf -S -s rasm2.o >> rasm2.o.re
	echo "% " >> rasm2.o.re

rasm.re :	rasm
	echo "% readelf -S -s rasm" > rasm.re
	readelf -S -s rasm | head -n 5 >> rasm.re
	cat ../../ellipsis.txt >> rasm.re
	readelf -S -s rasm | head -n 24 | tail -n 12 >> rasm.re
	cat ../../ellipsis.txt >> rasm.re
	readelf -S -s rasm | tail -n 80 | head -n 5 >> rasm.re
	cat ../../ellipsis.txt >> rasm.re
	readelf -S -s rasm | tail -n 33 >> rasm.re
	echo "% " >> rasm.re

rasm.o.ra :	rasm.o
	echo "% objdump -d rasm.o" > rasm.o.ra
	objdump -d rasm.o >> rasm.o.ra
	echo "% " >> rasm.o.ra

rasm2.o.ra :	rasm2.o
	echo "% objdump -d rasm2.o" > rasm2.o.ra
	objdump -d rasm2.o >> rasm2.o.ra
	echo "% " >> rasm2.o.ra

rasm.ra :	rasm
	echo "% objdump -d rasm" > rasm.ra
	cat ../../ellipsis.txt >> rasm.ra
	objdump -d rasm | head -n 173 | tail -n 38 >> rasm.ra
	cat ../../rest.txt >> rasm.ra
	echo "% " >> rasm.ra

clean :
	rm -f rasm *.o *.comp *.re *.ra
