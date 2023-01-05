OBJS=	pointer pointer.exec pointer.nm pointer.od \
	s1.size s2.size s1.out as1.out s2.out as2.out ns1.out ns2.out \
	rodata.out data.out eh_frame.out

all :	$(OBJS)

pointer :	pointer.c
	echo "% gcc pointer.c -Wall -o pointer" > pointer.comp
	gcc pointer.c -Wall -o pointer >> pointer.comp 2>&1

pointer.exec :	pointer
	echo "% ./pointer" > pointer.exec
	./pointer >> pointer.exec
	echo "% " >> pointer.exec

pointer.nm :	pointer
	echo "% nm pointer" > pointer.nm
	cat ../../ellipsis.txt >> pointer.nm
	nm pointer | grep s1 >> pointer.nm
	cat ../../ellipsis.txt >> pointer.nm
	nm pointer | grep s2 >> pointer.nm
	cat ../../rest.txt >> pointer.nm

pointer.od :	pointer
	echo "% objdump -h pointer" > pointer.od
	objdump -h pointer | head -n 5 >> pointer.od
	cat ../../ellipsis.txt >> pointer.od
	objdump -h pointer | head -n 31 | tail -n 6 >> pointer.od
	cat ../../rest.txt >> pointer.od

s1.size :	pointer.exec
	cat pointer.exec | grep "sizeof(s1)" | awk '{print $$3}' > s1.size

s2.size :	pointer.exec
	cat pointer.exec | grep "sizeof(s2)" | awk '{print $$3}' > s2.size

s1.out :	pointer.exec
	cat pointer.exec | grep " s1" | awk '{print $$3}' > s1.out

as1.out :	pointer.exec
	cat pointer.exec | grep "&s1" | awk '{print $$3}' > as1.out

s2.out :	pointer.exec
	cat pointer.exec | grep " s2" | awk '{print $$3}' > s2.out

as2.out :	pointer.exec
	cat pointer.exec | grep "&s2" | awk '{print $$3}' > as2.out

ns1.out :	pointer
	echo -n "0x" > ns1.out
	nm pointer | grep "s1" | awk '{print $$1}' >> ns1.out

ns2.out :	pointer
	echo -n "0x" > ns2.out
	nm pointer | grep "s2" | awk '{print $$1}' >> ns2.out

rodata.out :	pointer
	echo -n "0x" > rodata.out
	objdump -h pointer | grep "\.rodata" | awk '{print $$4}' >> rodata.out

data.out :	pointer
	echo -n "0x" > data.out
	objdump -h pointer | grep "\.data" | awk '{print $$4}' >> data.out

eh_frame.out :	pointer
	echo -n "0x" > eh_frame.out
	objdump -h pointer | grep "\.eh_frame" | awk '{print $$4}' >> eh_frame.out

clean :
	rm -f $(OBJS) *.comp

