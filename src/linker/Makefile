all :	linklib.o dynlink linker dynlink.exec linker.exec \
	sample.exec sample2.exec \
	sample.readelf sample2.readelf

linklib.o :	linklib.c
	echo "% gcc -c linklib.c -Wall" > linklib.comp
	gcc -c linklib.c -Wall >> linklib.comp 2>&1

dynlink :	linklib.o dynlink.c chflg.c
	echo "% gcc dynlink.c linklib.o -o dynlink -Wall" > dynlink.comp
	gcc dynlink.c linklib.o -o dynlink -Wall >> dynlink.comp 2>&1
	echo "% gcc chflg.c -o chflg -Wall" >> dynlink.comp
	gcc chflg.c -o chflg -Wall >> dynlink.comp 2>&1
	echo "% ./chflg ./dynlink" >> dynlink.comp
	./chflg ./dynlink >> dynlink.comp 2>&1
	echo "% " >> dynlink.comp

linker :	linklib.o linker.c
	echo "% gcc linker.c linklib.o -o linker -Wall" > linker.comp
	gcc linker.c linklib.o -o linker -Wall >> linker.comp 2>&1
	echo "% " >> linker.comp

sample :	main.c sample.c sample2.c service.c syscall.s
	echo "% gcc -c main.c -Wall -fno-builtin" > sample.comp
	gcc -c main.c -Wall -fno-builtin >> sample.comp 2>&1
	echo "% gcc -c sample.c -Wall -fno-builtin" >> sample.comp
	gcc -c sample.c -Wall -fno-builtin >> sample.comp 2>&1
	echo "% gcc -c sample2.c -Wall -fno-builtin" >> sample.comp
	gcc -c sample2.c -Wall -fno-builtin >> sample.comp 2>&1
	echo "% gcc -c crt.c -Wall -fno-builtin" >> sample.comp
	gcc -c crt.c -Wall -fno-builtin >> sample.comp 2>&1
	echo "% gcc -c service.c -Wall -fno-builtin" >> sample.comp
	gcc -c service.c -Wall -fno-builtin >> sample.comp 2>&1
	echo "% gcc -c syscall.s -Wall -fno-builtin" >> sample.comp
	gcc -c syscall.s -Wall -fno-builtin >> sample.comp 2>&1
	echo "% gcc main.o sample.o sample2.o crt.o service.o syscall.o -o sample -Wall -nostdlib" >> sample.comp
	gcc main.o sample.o sample2.o crt.o service.o syscall.o -o sample -Wall -nostdlib >> sample.comp 2>&1
	echo "% " >> sample.comp

dynlink.exec :	dynlink sample
	echo "% ./dynlink sample_main sample.o sample2.o service.o syscall.o" > dynlink.exec
	./dynlink sample_main sample.o sample2.o service.o syscall.o >> dynlink.exec 2>&1
	echo "% " >> dynlink.exec

sample.exec :	sample
	echo "% ./sample abc def ghi" > sample.exec
	./sample abc def ghi >> sample.exec 2>&1
	echo "% " >> sample.exec

linker.exec :	linker sample crt.o
	echo "% ./linker sample2 main.o sample.o sample2.o service.o syscall.o crt.o" > linker.exec
	./linker sample2 main.o sample.o sample2.o service.o syscall.o crt.o >> linker.exec 2>&1
	echo "% " >> linker.exec
	echo "% ls sample2" >> linker.exec
	ls sample2 >> linker.exec 2>&1
	echo "% " >> linker.exec

sample2.exec :	linker.exec
	echo "% chmod +x sample2" > sample2.exec
	chmod +x sample2 >> sample2.exec 2>&1
	echo "% ./sample2 abc def ghi" >> sample2.exec
	./sample2 abc def ghi >> sample2.exec 2>&1
	echo "% " >> sample2.exec

sample.readelf :	sample
	echo "% readelf -a ./sample" > sample.readelf
	readelf -a ./sample >> sample.readelf 2>&1
	echo "% " >> sample.readelf

sample2.readelf :	linker.exec
	echo "% readelf -a ./sample2" > sample2.readelf
	readelf -a ./sample2 >> sample2.readelf 2>&1
	echo "% " >> sample2.readelf

clean :
	rm -f dynlink chflg linker sample sample2 *.o *.comp *.exec *.readelf
