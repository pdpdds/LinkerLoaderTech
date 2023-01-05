OBJS=	section section.exec section.nm section.od

all :	$(OBJS)

section :	section.c
	echo "% gcc section.c -Wall -o section" > section.comp
	gcc section.c -Wall -o section >> section.comp 2>&1
	echo "% " >> section.comp

section.exec :	section
	echo "% ./section" > section.exec
	./section >> section.exec
	echo "% " >> section.exec

section.nm :	section
	echo "% nm section" > section.nm
	cat ../../ellipsis.txt >> section.nm
	nm section | grep test_section >> section.nm
	cat ../../ellipsis.txt >> section.nm
	nm section | grep fp >> section.nm
	cat ../../rest.txt >> section.nm

section.od :	section
	echo "% objdump -h section" > section.od
	objdump -h section | head -n 5 >> section.od
	cat ../../ellipsis.txt >> section.od
	objdump -h section | head -n 31 | tail -n 2 >> section.od
	cat ../../rest.txt >> section.od

clean :
	rm -f $(OBJS) *.comp

