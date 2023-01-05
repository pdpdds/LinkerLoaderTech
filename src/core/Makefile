TARGET = down down.readelf down.core file.out core.readelf nm.out
CFLAGS += -O -Wall

all :	$(TARGET)

down :	down.c
	echo "% gcc down.c -o down -Wall" > down.comp
	gcc down.c -o down -Wall >> down.comp 2>&1
	echo "% " >> down.comp

down.readelf :	down
	readelf -S -l down > down.readelf

down.core :	down
	echo "% ./down" > down.out
	./down >> down.out 2>&1 &
	sleep 2
	echo "Segmentation fault (core dumped)" >> down.out
	echo "% ls *.core" >> down.out
	ls *.core >> down.out
	echo "% " >> down.out

file.out :	down.core
	echo "% file down.core" > file.out
	file down.core >> file.out
	echo "% " >> file.out

core.readelf :	down.core
	readelf -a down.core > core.readelf

nm.out :	down
	echo "% nm down | grep count" > nm.out
	nm down | grep count >> nm.out
	echo "% " >> nm.out

clean :
	rm -f $(TARGET) *.o *.core *.comp *.out
