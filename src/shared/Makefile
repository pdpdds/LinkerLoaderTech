all :	libsample.so libsample.a \
	sample_shared sample_static sample_shared.exec sample_static.exec \
	sample_shared.ldd \
	sample_pic.o.re libsample.so.1.re sample_shared.re \
	sample.o.re sample_static.re \
	sample_pic.o.ra libsample.so.1.ra sample_shared.ra sample_static.ra \
	libsample.so.1.got sample_shared.got \
	dlopen dlopen.exec

libsample.so :	sample.c
	echo "% gcc -fpic -c sample.c -o sample_pic.o -Wall" > libsample.so.comp
	gcc -fpic -c sample.c -o sample_pic.o -Wall >> libsample.so.comp 2>&1
	echo "% gcc -shared -Wl,-soname=libsample.so.1 sample_pic.o -o libsample.so.1" >> libsample.so.comp
	gcc -shared -Wl,-soname=libsample.so.1 sample_pic.o -o libsample.so.1 >> libsample.so.comp 2>&1
	echo "% ln -s libsample.so.1 libsample.so" >> libsample.so.comp
	ln -s libsample.so.1 libsample.so >> libsample.so.comp 2>&1
	echo "% " >> libsample.so.comp

sample_shared :	libsample.so libsample.a
	echo "% gcc -c main.c -Wall" > sample_shared.comp
	gcc -c main.c -Wall >> sample_shared.comp 2>&1
	echo "% gcc -Wl,-rpath=. main.o -L. -lsample -o sample_shared" >> sample_shared.comp
	gcc -Wl,-rpath=. main.o -L. -lsample -o sample_shared >> sample_shared.comp 2>&1
	echo "% " >> sample_shared.comp

sample_shared.exec :	sample_shared
	echo "% ./sample_shared" > sample_shared.exec
	./sample_shared >> sample_shared.exec 2>&1
	echo "% " >> sample_shared.exec

libsample.a :	sample.c
	echo "% gcc -c sample.c -Wall" > libsample.a.comp
	gcc -c sample.c -Wall >> libsample.a.comp 2>&1
	echo "% ar ruc libsample.a sample.o" >> libsample.a.comp
	ar ruc libsample.a sample.o >> libsample.a.comp 2>&1
	echo "% " >> libsample.a.comp

sample_static :	libsample.so libsample.a sample_shared
	echo "% gcc -static main.o -L. -lsample -o sample_static" > sample_static.comp
	gcc -static main.o -L. -lsample -o sample_static >> sample_static.comp 2>&1
	echo "% " >> sample_static.comp

sample_static.exec :	sample_static
	echo "% ./sample_static" > sample_static.exec
	./sample_static >> sample_static.exec 2>&1
	echo "% " >> sample_static.exec

sample_shared.ldd :	sample_shared
	echo "% ldd sample_shared" > sample_shared.ldd
	ldd sample_shared >> sample_shared.ldd 2>&1
	echo "% " >> sample_shared.ldd

sample_pic.o.re :	libsample.so
	echo "% readelf -a sample_pic.o" > sample_pic.o.re
	readelf -a sample_pic.o >> sample_pic.o.re
	echo "% " >> sample_pic.o.re

libsample.so.1.re :	libsample.so.1
	echo "% readelf -a libsample.so.1" > libsample.so.1.re
	readelf -a libsample.so.1 >> libsample.so.1.re
	echo "% " >> libsample.so.1.re

sample_shared.re :	sample_shared
	echo "% readelf -a sample_shared" > sample_shared.re
	readelf -a sample_shared >> sample_shared.re
	echo "% " >> sample_shared.re

sample.o.re :	sample.o
	echo "% readelf -a sample.o" > sample.o.re
	readelf -a sample.o >> sample.o.re
	echo "% " >> sample.o.re

sample_static.re :	sample_static
	echo "% readelf -a sample_static" > sample_static.re
	readelf -a sample_static >> sample_static.re
	echo "% " >> sample_static.re

sample_pic.o.ra :	sample_pic.o
	echo "objdump -d sample_pic.o" > sample_pic.o.ra
	objdump -d sample_pic.o | head -n 27 >> sample_pic.o.ra
	cat ../../rest.txt >> sample_pic.o.ra

libsample.so.1.ra :	libsample.so.1
	echo "% objdump -d libsample.so.1" > libsample.so.1.ra
	objdump -d libsample.so.1 | head -n 28 >> libsample.so.1.ra
	cat ../../rest.txt >> libsample.so.1.ra

sample_shared.ra :	sample_shared
	echo "% objdump -d sample_shared" > sample_shared.ra
	objdump -d sample_shared | head -n 31 >> sample_shared.ra
	cat ../../rest.txt >> sample_shared.ra

sample_static.ra :	sample_static
	echo "% objdump -d sample_static" > sample_static.ra
	objdump -d sample_static >> sample_static.ra
	echo "% " >> sample_static.ra

libsample.so.1.got :	libsample.so.1
	echo "% readelf -x 17 libsample.so.1" > libsample.so.1.got
	readelf -x 17 libsample.so.1 >> libsample.so.1.got
	echo "% " >> libsample.so.1.got

sample_shared.got :	sample_shared
	echo "% readelf -x 18 sample_shared" > sample_shared.got
	readelf -x 18 sample_shared >> sample_shared.got
	echo "% " >> sample_shared.got

dlopen :	dlopen.c
	echo "% gcc dlopen.c -o dlopen" > dlopen.comp
	gcc dlopen.c -o dlopen >> dlopen.comp 2>&1
	echo "% " >> dlopen.comp

dlopen.exec :	dlopen
	echo "% ./dlopen" > dlopen.exec
	./dlopen >> dlopen.exec 2>&1
	echo "% " >> dlopen.exec

clean :
	rm -f *.SO *.so *.so.? *.a *.o *.comp *.exec *.ldd *.re *.ra *.got \
		sample_shared sample_static dlopen
