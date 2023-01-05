OBJS=	samp_obj samp_ar samp_obj.sym samp_ar.sym \
	samp2_obj samp2_ar samp2_obj.sym samp2_ar.sym

all :	$(OBJS)

libsamp.a :
	echo "% gcc -c samp1.c -Wall" > libsamp.comp
	gcc -c samp1.c -Wall >> libsamp.comp 2>&1
	echo "% gcc -c samp2.c -Wall" >> libsamp.comp
	gcc -c samp2.c -Wall >> libsamp.comp 2>&1
	echo "% gcc -c samp3.c -Wall" >> libsamp.comp
	gcc -c samp3.c -Wall >> libsamp.comp 2>&1
	echo "% gcc -c samp4.c -Wall" >> libsamp.comp
	gcc -c samp4.c -Wall >> libsamp.comp 2>&1
	echo "% ar ruc libsamp.a samp?.o" >> libsamp.comp
	ar ruc libsamp.a samp?.o >> libsamp.comp
	echo "% " >> libsamp.comp

libsamp2.a :	libsamp.a
	echo "% gcc -c samp2.c -Wall" > libsamp2.comp
	gcc -c samp2d.c -Wall >> libsamp2.comp 2>&1
	echo "% ar ruc libsamp.a samp2.o" >> libsamp2.comp
	ar ruc libsamp2.a samp1.o samp2d.o samp3.o samp4.o >> libsamp2.comp
	echo "% " >> libsamp2.comp

ardump :	../ar/ardump.c
	gcc ../ar/ardump.c -Wall -o ardump

samp_obj :	libsamp.a
	echo "% gcc main.c samp?.o -Wall -o samp_obj" > samp_obj.comp
	gcc main.c samp?.o -Wall -o samp_obj >> samp_obj.comp 2>&1
	echo "% " >> samp_obj.comp

samp_ar :	libsamp.a
	echo "% gcc main.c -Wall -L. -lsamp -o samp_ar" > samp_ar.comp
	gcc main.c -Wall -L. -lsamp -o samp_ar >> samp_ar.comp 2>&1
	echo "% " >> samp_ar.comp

samp_obj.sym :	samp_obj ardump
	echo "% ./ardump samp_obj | grep samp" > samp_obj.sym
	./ardump samp_obj | grep samp >> samp_obj.sym

samp_ar.sym :	samp_ar ardump
	echo "% ./ardump samp_ar | grep samp" > samp_ar.sym
	./ardump samp_ar | grep samp >> samp_ar.sym

samp2_obj :	libsamp2.a
	echo "% gcc main.c samp?.o -Wall -o samp2_obj" > samp2_obj.comp
	gcc main.c samp1.o samp2d.o samp3.o samp4.o -Wall -o samp2_obj >> samp2_obj.comp 2>&1
	echo "% " >> samp2_obj.comp

samp2_ar :	libsamp2.a
	echo "% gcc main.c -Wall -L. -lsamp -o samp2_ar" > samp2_ar.comp
	gcc main.c -Wall -L. -lsamp2 -o samp2_ar >> samp2_ar.comp 2>&1
	echo "% " >> samp2_ar.comp

samp2_obj.sym :	samp2_obj ardump
	echo "% ./ardump samp2_obj | grep samp" > samp2_obj.sym
	./ardump samp2_obj | grep samp | sed -e 's/samp2d/samp2/' >> samp2_obj.sym

samp2_ar.sym :	samp2_ar ardump
	echo "% ./ardump samp2_ar | grep samp" > samp2_ar.sym
	./ardump samp2_ar | grep samp | sed -e 's/samp2d/samp2/' >> samp2_ar.sym

clean :
	rm -f $(OBJS) *.a *.o *.comp *.tmp ardump*
