OBJS=	hello gcc-v.out tmp_o.out \
	size.out objdump.out objdump-p.out hello_dump.txt

all :	$(OBJS)

gcc-v.out :	hello

hello :	hello.c
	echo "% gcc hello.c -Wall -o hello -v" > gcc-v.out
	gcc hello.c -Wall -o hello -v >> gcc-v.out 2>&1
	echo "% " >> gcc-v.out

tmp_o.out : gcc-v.out
	cat gcc-v.out | grep /usr/libexec/elf/ld | awk '{print $$11}' \
		> tmp_o.out

size.out :	hello
	size hello > size.out

objdump.out :	hello
	objdump -h hello > objdump.out

objdump-p.out :	hello
	objdump -p hello > objdump-p.out

hello_dump.txt :	hello
	echo "% hexdump -C hello | head -n 3" > hello_dump.txt
	hexdump -C hello | head -n 3 >> hello_dump.txt
	echo "% " >> hello_dump.txt

clean :
	rm -f $(OBJS)

