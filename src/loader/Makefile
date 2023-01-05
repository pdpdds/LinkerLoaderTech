TARGET = ls.shdr ls.phdr gcc.shdr \
	chelf chflg ldscript.diff \
	sample loader sample.out loader.out
CFLAGS += -O -Wall

all :	$(TARGET)

ls.shdr :
	echo "% readelf -S /bin/ls" > ls.shdr
	readelf -S /bin/ls >> ls.shdr
	echo "% " >> ls.shdr

ls.phdr :
	echo "% readelf -l /bin/ls" > ls.phdr
	readelf -l /bin/ls >> ls.phdr
	echo "% " >> ls.phdr

gcc.shdr :
	echo "% readelf -S /usr/bin/gcc" > gcc.shdr
	readelf -S /usr/bin/gcc >> gcc.shdr
	echo "% " >> gcc.shdr

chelf :	chelf.c
	echo "% gcc chelf.c -o chelf -Wall" > chelf.comp
	gcc chelf.c -o chelf -Wall >> chelf.comp 2>&1
	echo "% " >> chelf.comp

chflg :	chflg.c
	echo "% gcc chflg.c -o chflg -Wall" > chflg.comp
	gcc chflg.c -o chflg -Wall >> chflg.comp 2>&1
	echo "% " >> chflg.comp

ldscript.diff :	elf_i386.x space.scr
	diff -u -U 7 elf_i386.x space.scr > ldscript.diff &
	sleep 1

sample :	sample.c
	echo "% gcc sample.c -o sample -static -Wall" > sample.comp
	gcc sample.c -o sample -static -Wall >> sample.comp 2>&1
	echo "% " >> sample.comp

loader :	loader.c chflg
	echo "% gcc loader.c -o loader -T space.scr -static -Wall" > loader.comp
	gcc loader.c -o loader -T space.scr -static -Wall >> loader.comp 2>&1
	echo "% ./chflg loader" >> loader.comp
	./chflg loader >> loader.comp 2>&1
	echo "% " >> loader.comp

sample.out :	sample
	echo "% ./sample abc def ghi" > sample.out
	./sample abc def ghi >> sample.out 2>&1
	echo "% " >> sample.out

loader.out :	loader sample
	echo "% ./loader sample abc def ghi" > loader.out
	./loader sample abc def ghi >> loader.out 2>&1
	echo "% " >> loader.out

clean :
	rm -f $(TARGET) *.o *.core *.comp
