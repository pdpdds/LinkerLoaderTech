TARGET = chflg.c chflg elf_i386.x space.scr ldscript.diff \
	calc continue calc.out core.out continue.out
CFLAGS += -O -Wall

all :	$(TARGET)

chflg.c :	../loader/chflg.c
	cp ../loader/chflg.c .

chflg :	chflg.c
	echo "% gcc chflg.c -o chflg -Wall" > chflg.comp
	gcc chflg.c -o chflg -Wall >> chflg.comp 2>&1
	echo "% " >> chflg.comp

elf_i386.x :	../loader/elf_i386.x
	cp ../loader/elf_i386.x .

space.scr :	../loader/space.scr
	cp ../loader/space.scr .

ldscript.diff : elf_i386.x space.scr
	diff -u -U 7 elf_i386.x space.scr > ldscript.diff &
	sleep 1

calc :	calc.c
	echo "% gcc calc.c -o calc -static -Wall" > calc.comp
	gcc calc.c -o calc -static -Wall >> calc.comp 2>&1
	echo "% " >> calc.comp

continue :	continue.c chflg
	echo "% gcc continue.c -o continue -T space.scr -static -Wall" > continue.comp
	gcc continue.c -o continue -T space.scr -static -Wall >> continue.comp 2>&1
	echo "% ./chflg continue" >> continue.comp
	./chflg continue >> continue.comp 2>&1
	echo "% " >> continue.comp

calc.out :	calc
	echo "% ./calc" > calc.out
	./calc >> calc.out 2>&1
	echo "% " >> calc.out

core.out :	continue calc
	echo "% ./calc" > core.out
	./calc >> core.out 2>&1 &
	sleep 3
	killall -ABRT calc
	sleep 2
	echo "Abort (core dumped)" >> core.out
	echo "% " >> core.out

continue.out :	continue calc core.out
	echo "% ./continue calc calc.core" > continue.out
	./continue calc calc.core >> continue.out 2>&1
	echo "% " >> continue.out

clean :
	rm -f $(TARGET) *.o *.core *.comp
