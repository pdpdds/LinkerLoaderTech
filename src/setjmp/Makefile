TARGET = setjmp setjmp2
CFLAGS += -O -Wall

all :	$(TARGET)

setjmp :	setjmp.c
	echo "% gcc setjmp.c -o setjmp -Wall" > setjmp.out
	gcc setjmp.c -o setjmp -Wall >> setjmp.out 2>&1
	echo "% " >> setjmp.out
	echo "% ./setjmp" >> setjmp.out
	./setjmp >> setjmp.out 2>&1
	echo "% " >> setjmp.out

setjmp2 :	setjmp2.c
	echo "% gcc setjmp2.c -o setjmp2 -Wall" > setjmp2.out
	gcc setjmp2.c -o setjmp2 -Wall >> setjmp2.out 2>&1
	echo "% " >> setjmp2.out
	echo "% ./setjmp2" >> setjmp2.out
	./setjmp2 >> setjmp2.out 2>&1
	echo "% " >> setjmp2.out

clean :
	rm -f $(TARGET) *.out
