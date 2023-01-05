OBJS=	values values.out values_sub.o values_nm.out values_c.out \
	values_sub_nm.out objdump.out strip.out

all :	$(OBJS)

values :	values.c values_sub.o
	echo "% gcc values.c values_sub.o -o values" > values-comp.out
	gcc values.c values_sub.o -o values >> values-comp.out 2>&1
	echo "% " >> values-comp.out

values.out :	values
	echo "% ./values" > values.out
	./values >> values.out
	echo "% " >> values.out

values_sub.o :	values_sub.c
	echo "% gcc -c values_sub.c" > values_sub.out
	gcc -c values_sub.c >> values_sub.out 2>&1
	echo "% ls values_sub.o" >> values_sub.out
	ls values_sub.o >> values_sub.out 2>&1
	echo "% " >> values_sub.out

values_nm.out :	values
	echo "% nm values" > values_nm.out
	nm values | head -n 3 >> values_nm.out
	cat ../../ellipsis.txt >> values_nm.out
	nm values | tail -n 40 >> values_nm.out
	echo "% " >> values_nm.out

values_c.out :	values
	echo -n "0x" > values_c.out
	echo -n "0x" > values_i1.out
	echo -n "0x" > values_i2.out
	echo -n "0x" > values_p1.out
	echo -n "0x" > values_str.out
	echo -n "0x" > values_si1.out
	echo -n "0x" > values_si2.out
	echo -n "0x" > values_ci0.out
	echo -n "0x" > values_i0.out
	echo -n "0x" > values_p0.out
	echo -n "0x" > values_si0.out
	echo -n "0x" > values_ci1.out
	echo -n "0x" > values_ci2.out
	echo -n "0x" > values_main.out
	echo -n "0x" > values_func.out
	nm values | grep " D c"    | awk '{print $$1}' >> values_c.out
	nm values | grep " D i1"   | awk '{print $$1}' >> values_i1.out
	nm values | grep " D i2"   | awk '{print $$1}' >> values_i2.out
	nm values | grep " D p1"   | awk '{print $$1}' >> values_p1.out
	nm values | grep " D str"  | awk '{print $$1}' >> values_str.out
	nm values | grep " d si1"  | awk '{print $$1}' >> values_si1.out
	nm values | grep " d si2"  | awk '{print $$1}' >> values_si2.out
	nm values | grep " B ci0"  | awk '{print $$1}' >> values_ci0.out
	nm values | grep " B i0"   | awk '{print $$1}' >> values_i0.out
	nm values | grep " B p0"   | awk '{print $$1}' >> values_p0.out
	nm values | grep " b si0"  | awk '{print $$1}' >> values_si0.out
	nm values | grep " R ci1"  | awk '{print $$1}' >> values_ci1.out
	nm values | grep " R ci2"  | awk '{print $$1}' >> values_ci2.out
	nm values | grep " T main" | awk '{print $$1}' >> values_main.out
	nm values | grep " T func" | awk '{print $$1}' >> values_func.out

values_sub_nm.out :	values_sub.o
	echo "% nm values_sub.o" > values_sub_nm.out
	nm values_sub.o >> values_sub_nm.out
	echo "% " >> values_sub_nm.out

objdump.out :	values
	echo "% objdump -h values" > objdump.out
	objdump -h values | head -n 5 >> objdump.out
	cat ../../ellipsis.txt >> objdump.out
	objdump -h values | head -n 29 | tail -n 8 >> objdump.out
	cat ../../ellipsis.txt >> objdump.out
	objdump -h values | head -n 41 | tail -n 2 >> objdump.out
	cat ../../rest.txt >> objdump.out

strip.out :	values objdump.out values.out
	mv values values.bak
	cp values.bak values
	echo "% ls -l values" > strip.out
	ls -l values >> strip.out
	echo "% file values" >> strip.out
	file values >> strip.out
	echo "% strip values" >> strip.out
	strip values >> strip.out
	echo "% ls -l values" >> strip.out
	ls -l values >> strip.out
	echo "% file values" >> strip.out
	file values >> strip.out
	echo "% nm values" >> strip.out
	nm values >> strip.out 2>&1
	mv values.bak values

clean :
	rm -f $(OBJS) *.o *.out

