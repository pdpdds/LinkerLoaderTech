TARGET = global.exec noglobal.exec \
	global_a.exec noglobal_a.exec \
	weak.o.nm global.nm noglobal.nm

all :	$(TARGET)

global :	main.o
	echo "% gcc main.o weak.o global.o -o global -Wall" > global.comp
	gcc main.o weak.o global.o -o global -Wall >> global.comp 2>&1

noglobal :	main.o
	echo "% gcc main.o weak.o -o noglobal -Wall" > noglobal.comp
	gcc main.o weak.o -o noglobal -Wall >> noglobal.comp 2>&1
	echo "% " >> noglobal.comp

global_a :	main.o weak.a
	echo "% gcc main.o -L. -lweak -lglobal -o global_a -Wall" > global_a.comp
	gcc main.o -L. -lweak -lglobal -o global_a -Wall >> global_a.comp 2>&1
	echo "% " >> global_a.comp

noglobal_a :	main.o weak.a
	echo "% gcc main.o -L. -lweak -o noglobal_a -Wall" > noglobal_a.comp
	gcc main.o -L. -lweak -o noglobal_a -Wall >> noglobal_a.comp 2>&1
	echo "% " >> noglobal_a.comp

main.o :	main.c weak.c global.c
	echo "% gcc -c main.c -Wall" > main.o.comp
	gcc -c main.c -Wall >> main.o.comp 2>&1
	echo "% gcc -c weak.c -Wall" >> main.o.comp
	gcc -c weak.c -Wall >> main.o.comp 2>&1
	echo "% gcc -c global.c -Wall" >> main.o.comp
	gcc -c global.c -Wall >> main.o.comp 2>&1
	echo "% " >> main.o.comp

weak.a :	main.o
	echo "% ar ruc libweak.a weak.o" > weak.a.comp
	ar ruc libweak.a weak.o >> weak.a.comp 2>&1
	echo "% ar ruc libglobal.a global.o" >> weak.a.comp
	ar ruc libglobal.a global.o >> weak.a.comp 2>&1

global.exec :	global
	./global > global.exec

noglobal.exec :	noglobal
	./noglobal > noglobal.exec

global_a.exec :	global_a
	./global_a > global_a.exec

noglobal_a.exec :	noglobal_a
	./noglobal_a > noglobal_a.exec

weak.o.nm :	main.o
	echo "% nm weak.o | grep sample" > weak.o.nm
	nm weak.o | grep sample >> weak.o.nm
	echo "% " >> weak.o.nm

global.nm :	global
	echo "% nm global | grep sample" > global.nm
	nm global | grep sample >> global.nm
	echo "% " >> global.nm

noglobal.nm :	noglobal
	echo "% nm noglobal | grep sample" > noglobal.nm
	nm noglobal | grep sample >> noglobal.nm
	echo "% " >> noglobal.nm

clean :
	rm -f *.o *.a *.comp *.exec *.nm global noglobal global_a noglobal_a
