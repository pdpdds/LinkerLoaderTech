OBJS=	elfsamp elfsamp.exec \
	readelf-h.out readelf-x.out readelf-l.out \
	readelf-S.out readelf-s.out readelf-r.out \
	readelf-o-h.out readelf-o-x.out readelf-o-l.out \
	readelf-o-S.out readelf-o-s.out readelf-o-r.out \
	text_off-o-S.out text_vaddr-l.out \
	data_off-l.out data_vaddr-l.out data_fsize-l.out data_msize-l.out \
	shstr-o-h.out shstr_idx-o-h.out \
	readsec readsec.exec readsec-s.out readsec-r.out \
	elfdump elfdump.exec elfdump-o.exec

all :	$(OBJS)

elfsamp :	elfsamp.c main.c
	echo "% gcc -c elfsamp.c -Wall" > elfsamp.comp
	gcc -c elfsamp.c -Wall >> elfsamp.comp 2>&1
	echo "% gcc -c main.c -Wall" >> elfsamp.comp
	gcc -c main.c -Wall >> elfsamp.comp 2>&1
	echo "% gcc elfsamp.o main.o -Wall -o elfsamp" >> elfsamp.comp
	gcc elfsamp.o main.o -Wall -o elfsamp >> elfsamp.comp 2>&1

elfsamp.exec :	elfsamp
	echo "% ./elfsamp" > elfsamp.exec
	./elfsamp >> elfsamp.exec
	echo "% " >> elfsamp.exec

readelf-h.out :	elfsamp
	echo "% readelf -h elfsamp" > readelf-h.out
	readelf -h elfsamp >> readelf-h.out
	echo "% " >> readelf-h.out

readelf-S.out :	elfsamp
	echo "% readelf -S elfsamp" > readelf-S.out
	readelf -S elfsamp >> readelf-S.out
	echo "% " >> readelf-S.out

readelf-s.out :	elfsamp
	echo "% readelf -s elfsamp" > readelf-s.out
	readelf -s elfsamp >> readelf-s.out
	echo "% " >> readelf-s.out

readelf-r.out :	elfsamp
	echo "% readelf -r elfsamp" > readelf-r.out
	readelf -r elfsamp >> readelf-r.out
	echo "% " >> readelf-r.out

readelf-l.out :	elfsamp
	echo "% readelf -l elfsamp" > readelf-l.out
	readelf -l elfsamp >> readelf-l.out
	echo "% " >> readelf-l.out

readelf-x.out :	elfsamp
	echo "% readelf -x 22 elfsamp" > readelf-x.out
	readelf -x 22 elfsamp >> readelf-x.out
	echo "% " >> readelf-x.out

readelf-o-h.out :	elfsamp
	echo "% readelf -h elfsamp.o" > readelf-o-h.out
	readelf -h elfsamp.o >> readelf-o-h.out
	echo "% " >> readelf-o-h.out

readelf-o-S.out :	elfsamp
	echo "% readelf -S elfsamp.o" > readelf-o-S.out
	readelf -S elfsamp.o >> readelf-o-S.out
	echo "% " >> readelf-o-S.out

readelf-o-s.out :	elfsamp
	echo "% readelf -s elfsamp.o" > readelf-o-s.out
	readelf -s elfsamp.o >> readelf-o-s.out
	echo "% " >> readelf-o-s.out

readelf-o-r.out :	elfsamp
	echo "% readelf -r elfsamp.o" > readelf-o-r.out
	readelf -r elfsamp.o >> readelf-o-r.out
	echo "% " >> readelf-o-r.out

readelf-o-l.out :	elfsamp
	echo "% readelf -l elfsamp.o" > readelf-o-l.out
	readelf -l elfsamp.o >> readelf-o-l.out
	echo "% " >> readelf-o-l.out

readelf-o-x.out :	elfsamp
	echo "% readelf -x 8 elfsamp.o" > readelf-o-x.out
	readelf -x 8 elfsamp.o >> readelf-o-x.out
	echo "% " >> readelf-o-x.out

text_off-o-S.out :	readelf-o-S.out
	echo -n "0x" > text_off-o-S.out
	cat readelf-o-S.out | grep text | grep PROGBITS | \
		awk '{print $$6}' >> text_off-o-S.out

text_vaddr-l.out :	readelf-l.out
	cat readelf-l.out | grep LOAD | grep "R E" | \
		awk '{print $$3}' > text_vaddr-l.out

data_off-l.out :	readelf-l.out
	cat readelf-l.out | grep LOAD | grep RW | \
		awk '{print $$2}' > data_off-l.out

data_vaddr-l.out :	readelf-l.out
	cat readelf-l.out | grep LOAD | grep RW | \
		awk '{print $$3}' > data_vaddr-l.out

data_fsize-l.out :	readelf-l.out
	cat readelf-l.out | grep LOAD | grep RW | \
		awk '{print $$5}' > data_fsize-l.out

data_msize-l.out :	readelf-l.out
	cat readelf-l.out | grep LOAD | grep RW | \
		awk '{print $$6}' > data_msize-l.out

shstr-o-h.out :	readelf-o-h.out
	cat readelf-o-h.out | grep "Section header string" > shstr-o-h.out

shstr_idx-o-h.out :	shstr-o-h.out
	cat shstr-o-h.out | awk '{print $$6}' > shstr_idx-o-h.out

readsec :	readsec.c
	echo "% gcc -c readsec.c -Wall" > readsec.comp
	gcc -c readsec.c -Wall >> readsec.comp 2>&1
	echo "% gcc readsec.o -Wall -o readsec" >> readsec.comp
	gcc readsec.o -Wall -o readsec >> readsec.comp 2>&1

readsec.exec :	readsec elfsamp.o
	echo "% ./readsec elfsamp.o" > readsec.exec
	./readsec elfsamp.o >> readsec.exec
	echo "% " >> readsec.exec

readsec-s.out :	readsec
	echo "% readelf -s readsec.o" > readsec-s.out
	readelf -s readsec.o >> readsec-s.out

readsec-r.out :	readsec
	echo "% readelf -r readsec.o" > readsec-r.out
	readelf -r readsec.o >> readsec-r.out

elfdump :	elfdump.c
	echo "% gcc -c elfdump.c -Wall" > elfdump.comp
	gcc -c elfdump.c -Wall >> elfdump.comp 2>&1
	echo "% gcc elfdump.o -Wall -o elfdump" >> elfdump.comp
	gcc elfdump.o -Wall -o elfdump >> elfdump.comp 2>&1

elfdump.exec :	elfdump elfsamp
	echo "% ./elfdump elfsamp" > elfdump.exec
	./elfdump elfsamp | head -n 3 >> elfdump.exec
	cat ../../ellipsis.txt >> elfdump.exec
	./elfdump elfsamp | head -n 37 | tail -n 11 >> elfdump.exec
	cat ../../rest.txt >> elfdump.exec
	echo "% " >> elfdump.exec

elfdump-o.exec :	elfdump elfsamp.o
	echo "% ./elfdump elfsamp.o" > elfdump-o.exec
	./elfdump elfsamp.o >> elfdump-o.exec
	echo "% " >> elfdump-o.exec

clean :
	rm -f $(OBJS) *.o *.comp
