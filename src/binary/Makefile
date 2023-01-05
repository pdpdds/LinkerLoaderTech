OBJS=	binary.o binary binary.dat binary.exec binary.nm binary.od \
	binary2 binary2.exec binary3 binary3.exec

all :	$(OBJS)

binary.dat :
	echo "% echo \"This is test.\" > binary.dat" > binary.dat.comp
	echo "This is test." > binary.dat

binary.o :	binary.c
	echo "% gcc -c binary.c -Wall" > binary.o.comp
	gcc -c binary.c -Wall >> binary.o.comp 2>&1

binary :	binary.o binary.dat
	echo "% objcopy --add-section=bindata=binary.dat --set-section-flags=bindata=contents,alloc,load,readonly,data binary.o binary_tmp.o" > binary.comp
	objcopy --add-section=bindata=binary.dat --set-section-flags=bindata=contents,alloc,load,readonly,data binary.o binary_tmp.o >> binary.comp 2>&1
	echo "% gcc binary_tmp.o -Wall -o binary" >> binary.comp
	gcc binary_tmp.o -Wall -o binary >> binary.comp 2>&1
	echo "% " >> binary.comp

binary.exec :	binary
	echo "% ./binary" > binary.exec
	./binary >> binary.exec
	echo "% " >> binary.exec

binary2 :	binary.o binary.dat incbin.s
	echo "% gcc -c incbin.s" > binary2.comp
	gcc -c incbin.s >> binary2.comp 2>&1
	echo "% gcc binary.o incbin.o -o binary2" >> binary2.comp
	gcc binary.o incbin.o -o binary2 >> binary2.comp 2>&1
	echo "% " >> binary2.comp

binary2.exec :	binary2
	echo "% ./binary2" > binary2.exec
	./binary2 >> binary2.exec
	echo "% " >> binary2.exec

binary3 :	binary.o binary.dat
	echo "% ld --format binary --oformat elf32-i386 -r binary.dat -o binary_tmp2.o" > binary3.comp
	ld --format binary --oformat elf32-i386 -r binary.dat -o binary_tmp2.o >> binary3.comp 2>&1
	echo "% ld -r -T bindata.scr binary_tmp2.o -o binary_tmp3.o" > binary3_2.comp
	ld -r -T bindata.scr binary_tmp2.o -o binary_tmp3.o >> binary3_2.comp 2>&1
	echo "% gcc binary.o binary_tmp3.o -o binary3" > binary3_3.comp
	gcc binary.o binary_tmp3.o -o binary3 >> binary3_3.comp 2>&1
	echo "% " >> binary3_3.comp

binary3.exec :	binary3
	echo "% ./binary3" > binary3.exec
	./binary3 >> binary3.exec
	echo "% " >> binary3.exec

binary.nm :	binary
	echo "% nm binary" > binary.nm
	cat ../../ellipsis.txt >> binary.nm
	nm binary | grep start_bindata >> binary.nm
	cat ../../ellipsis.txt >> binary.nm
	nm binary | grep stop_bindata >> binary.nm
	cat ../../rest.txt >> binary.nm

binary.od :	binary
	echo "% objdump -h binary" > binary.od
	objdump -h binary | head -n 5 >> binary.od
	cat ../../ellipsis.txt >> binary.od
	objdump -h binary | head -n 31 | tail -n 2 >> binary.od
	cat ../../rest.txt >> binary.od

clean :
	rm -f $(OBJS) *.o *.comp

