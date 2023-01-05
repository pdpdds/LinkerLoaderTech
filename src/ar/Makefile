OBJS=	files.out ar.out \
	readname readname.exec \
	ardump ardump.exec ardump.exec2

all :	$(OBJS)

files.out :
	echo "% echo ABCD   > file15xxxxx.txt" > files.out
	echo ABCD   > file15xxxxx.txt
	echo "% echo ABCDE  > file16xxxxxx.txt" >> files.out
	echo ABCDE  > file16xxxxxx.txt
	echo "% echo ABCDEF > file17xxxxxxx.txt" >> files.out
	echo ABCDEF > file17xxxxxxx.txt

ar.out :	files.out
	echo "% /usr/libexec/aout/ar ruc bsdar.a file*.txt" > ar.out
	/usr/libexec/aout/ar ruc bsdar.a file*.txt
	echo "% /usr/bin/ar ruc gnuar.a file*.txt" >> ar.out
	/usr/bin/ar ruc gnuar.a file*.txt

readname :	readname.c
	echo "% gcc readname.c -Wall -o readname" > readname.comp
	gcc readname.c -Wall -o readname >> readname.comp 2>&1

readname.exec :	readname ar.out
	echo "% ./readname gnuar.a" > readname.exec
	./readname gnuar.a >> readname.exec 2>&1
	echo "% " >> readname.exec

ardump :	ardump.c
	echo "% gcc -c ardump.c -Wall" > ardump.comp
	gcc -c ardump.c -Wall >> ardump.comp 2>&1
	echo "% gcc ardump.o -Wall -o ardump" >> ardump.comp
	gcc ardump.o -Wall -o ardump >> ardump.comp 2>&1

ardump.exec :	ardump ar.out
	echo "% ./ardump ardump.o" > ardump.exec
	./ardump ardump.o > ardump.exec.tmp 2>&1
	cat ardump.exec.tmp | head -n 15 >> ardump.exec
	cat ../../rest.txt >> ardump.exec
	echo "% " >> ardump.exec

ardump.exec2 :	ardump ar.out
	echo "% ./ardump /usr/lib/libc.a" > ardump.exec2
	./ardump /usr/lib/libc.a > ardump.exec2.tmp 2>&1
	cat ardump.exec2.tmp | head -n 6 >> ardump.exec2
	cat ../../ellipsis.txt >> ardump.exec2
	cat ardump.exec2.tmp | head -n 77 | tail -n 20 >> ardump.exec2
	cat ../../ellipsis.txt >> ardump.exec2
	cat ardump.exec2.tmp | tail -n 5 >> ardump.exec2
	echo "% " >> ardump.exec2

clean :
	rm -f $(OBJS) *.txt *.a *.o *.comp *.tmp
