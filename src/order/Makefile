OBJS=	ordermain.o \
	normal normal_a \
	reverse reverse_a \
	duplicate duplicate_a \
	group_a \
	collect_a collect2_a

all :	$(OBJS)

ordermain.o :	ordermain.c order1.c order2.c
	echo "% gcc -c ordermain.c -Wall" > ordermain.o.comp
	gcc -c ordermain.c -Wall >> ordermain.o.comp 2>&1
	echo "% gcc -c order1.c -Wall" >> ordermain.o.comp
	gcc -c order1.c -Wall >> ordermain.o.comp 2>&1
	echo "% gcc -c order2.c -Wall" >> ordermain.o.comp
	gcc -c order2.c -Wall >> ordermain.o.comp 2>&1
	echo "% ar ruc liborder1.a order1.o" >> ordermain.o.comp
	ar ruc liborder1.a order1.o >> ordermain.o.comp 2>&1
	echo "% ar ruc liborder2.a order2.o" >> ordermain.o.comp
	ar ruc liborder2.a order2.o >> ordermain.o.comp 2>&1
	echo "% " >> ordermain.o.comp

normal :	ordermain.o
	echo "% gcc ordermain.o order1.o order2.o -o normal -Wall" > normal.comp
	gcc         ordermain.o order1.o order2.o -o normal -Wall >> normal.comp 2>&1
	echo "% ./normal" >> normal.comp 2>&1
	./normal >> normal.comp 2>&1

normal_a :	ordermain.o
	echo "% gcc ordermain.o -lorder1 -lorder2 -L. -o normal_a -Wall" > normal_a.comp
	gcc         ordermain.o -lorder1 -lorder2 -L. -o normal_a -Wall >> normal_a.comp 2>&1
	echo "% ./normal_a" >> normal_a.comp 2>&1
	./normal_a >> normal_a.comp 2>&1

reverse :	ordermain.o
	echo "% gcc ordermain.o order2.o order1.o -o reverse -Wall" > reverse.comp
	gcc         ordermain.o order2.o order1.o -o reverse -Wall >> reverse.comp 2>&1
	echo "% ./reverse" >> reverse.comp 2>&1
	./reverse >> reverse.comp 2>&1

reverse_a :	ordermain.o
	echo "% gcc ordermain.o -lorder2 -lorder1 -L. -o reverse_a -Wall" > reverse_a.comp
	gcc         ordermain.o -lorder2 -lorder1 -L. -o reverse_a -Wall >> reverse_a.comp 2>&1 &
	sleep 1

duplicate :	ordermain.o
	echo "% gcc ordermain.o order2.o order1.o order2.o -o duplicate -Wall" > duplicate.comp
	gcc         ordermain.o order2.o order1.o order2.o -o duplicate -Wall >> duplicate.comp 2>&1 &
	sleep 1

duplicate_a :	ordermain.o
	echo "% gcc ordermain.o -lorder2 -lorder1 -lorder2 -L. -o duplicate_a -Wall" > duplicate_a.comp
	gcc         ordermain.o -lorder2 -lorder1 -lorder2 -L. -o duplicate_a -Wall >> duplicate_a.comp 2>&1
	echo "% ./duplicate_a" >> duplicate_a.comp 2>&1
	./duplicate_a >> duplicate_a.comp 2>&1

group_a :	ordermain.o
	echo "% gcc ordermain.o --start-group -lorder2 -lorder1 --end-group -L. -o group_a -Wall" > group_a.comp
	gcc         ordermain.o -Wl,--start-group -lorder2 -lorder1 -Wl,--end-group -L. -o group_a -Wall >> group_a.comp 2>&1
	echo "% ./group_a" >> group_a.comp 2>&1
	./group_a >> group_a.comp 2>&1

collect_a :	ordermain.o
	echo "% ar ruc libcollect.a order1.o order2.o" > collect_a.comp
	ar ruc libcollect.a order1.o order2.o >> collect_a.comp 2>&1
	echo "% ar t libcollect.a" >> collect_a.comp
	ar t libcollect.a >> collect_a.comp 2>&1 2>&1 2>&1
	echo "% gcc ordermain.o -lcollect -L. -o collect_a -Wall" >> collect_a.comp
	gcc ordermain.o -lcollect -L. -o collect_a -Wall >> collect_a.comp 2>&1
	echo "% ./collect_a" >> collect_a.comp 2>&1
	./collect_a >> collect_a.comp 2>&1

collect2_a :	ordermain.o
	echo "% ar ruc libcollect2.a order2.o order1.o" > collect2_a.comp
	ar ruc libcollect2.a order2.o order1.o >> collect2_a.comp 2>&1
	echo "% ar t libcollect2.a" >> collect2_a.comp
	ar t libcollect2.a >> collect2_a.comp 2>&1
	echo "% gcc ordermain.o -lcollect2 -L. -o collect2_a -Wall" >> collect2_a.comp
	gcc ordermain.o -lcollect2 -L. -o collect2_a -Wall >> collect2_a.comp 2>&1
	echo "% ./collect2_a" >> collect2_a.comp 2>&1
	./collect2_a >> collect2_a.comp 2>&1

clean :
	rm -f $(OBJS) *.comp *.o *.a
