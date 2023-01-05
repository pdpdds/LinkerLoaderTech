OBJS=	main.o \
	normal normal_a \
	reverse reverse_a \
	duplicate duplicate_a \
	group_a

all :	$(OBJS)

main.o :	main.c test1.c test2.c
	echo "% gcc -c main.c -Wall" > main.o.comp
	gcc -c main.c -Wall >> main.o.comp 2>&1
	echo "% gcc -c test1.c -Wall" >> main.o.comp
	gcc -c test1.c -Wall >> main.o.comp 2>&1
	echo "% gcc -c test2.c -Wall" >> main.o.comp
	gcc -c test2.c -Wall >> main.o.comp 2>&1
	echo "% ar ruc libtest1.a test1.o" >> main.o.comp
	ar ruc libtest1.a test1.o >> main.o.comp 2>&1
	echo "% ar ruc libtest2.a test2.o" >> main.o.comp
	ar ruc libtest2.a test2.o >> main.o.comp 2>&1
	echo "% " >> main.o.comp

normal :	main.o
	echo "% gcc main.o test1.o test2.o -o normal -Wall" > normal.comp
	gcc         main.o test1.o test2.o -o normal -Wall >> normal.comp 2>&1

normal_a :	main.o
	echo "% gcc main.o -ltest1 -ltest2 -L. -o normal_a -Wall" > normal_a.comp
	gcc         main.o -ltest1 -ltest2 -L. -o normal_a -Wall >> normal_a.comp 2>&1

reverse :	main.o
	echo "% gcc main.o test2.o test1.o -o reverse -Wall" > reverse.comp
	gcc         main.o test2.o test1.o -o reverse -Wall >> reverse.comp 2>&1

reverse_a :	main.o
	echo "% gcc main.o -ltest2 -ltest1 -L. -o reverse_a -Wall" > reverse_a.comp
	gcc         main.o -ltest2 -ltest1 -L. -o reverse_a -Wall >> reverse_a.comp 2>&1 &
	sleep 1

duplicate :	main.o
	echo "% gcc main.o test2.o test1.o test2.o -o duplicate -Wall" > duplicate.comp
	gcc         main.o test2.o test1.o test2.o -o duplicate -Wall >> duplicate.comp 2>&1 &
	sleep 1

duplicate_a :	main.o
	echo "% gcc main.o -ltest2 -ltest1 -ltest2 -L. -o duplicate_a -Wall" > duplicate_a.comp
	gcc         main.o -ltest2 -ltest1 -ltest2 -L. -o duplicate_a -Wall >> duplicate_a.comp 2>&1

group_a :	main.o
	echo "% gcc main.o --start-group -ltest2 -ltest1 --end-group -L. -o group_a -Wall" > group_a.comp
	gcc         main.o -Wl,--start-group -ltest2 -ltest1 -Wl,--end-group -L. -o group_a -Wall >> group_a.comp 2>&1

clean :
	rm -f $(OBJS) *.comp *.o *.a
