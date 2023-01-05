OBJS=	app1.o app1 app1.exec app2.o app2 app2.exec \
	combine_app1.o combine_app2.o \
	app1.o.nm combine_app1.o.nm \
	app2.o.nm combine_app2.o.nm \
	combine combine.exec

all :	$(OBJS)

app1.o :	app1.c
	echo "% gcc -c app1.c -Wall" > app1.o.comp
	gcc -c app1.c -Wall >> app1.o.comp 2>&1

app1 :	app1.o
	rm -f app1
	echo "% gcc app1.o -Wall -o app1" > app1.comp
	gcc app1.o -Wall -o app1 >> app1.comp 2>&1

app1.exec :	app1
	echo "% ./app1" > app1.exec
	(./app1 2>&1 | cat) >> app1.exec &
	sleep 1
	echo "% " >> app1.exec

app2.o :	app2.c
	echo "% gcc -c app2.c -Wall" > app2.o.comp
	gcc -c app2.c -Wall >> app2.o.comp 2>&1

app2 :	app2.o
	rm -f app2
	echo "% gcc app2.o -Wall -o app2" > app2.comp
	gcc app2.o -Wall -o app2 >> app2.comp 2>&1

app2.exec :	app2
	echo "% ./app2" > app2.exec
	(./app2 2>&1 | cat) >> app2.exec &
	sleep 1
	echo "% " >> app2.exec

combine_app1.o :	app1.o
	echo "% objcopy --redefine-sym main=app1_main --redefine-sym exit=combine_exit app1.o combine_app1.o" > combine_app1.o.comp
	objcopy --redefine-sym main=app1_main --redefine-sym exit=combine_exit app1.o combine_app1.o >> combine_app1.o.comp

combine_app2.o :	app2.o
	echo "% objcopy --redefine-sym main=app2_main --redefine-sym exit=combine_exit app2.o combine_app2.o" > combine_app2.o.comp
	objcopy --redefine-sym main=app2_main --redefine-sym exit=combine_exit app2.o combine_app2.o >> combine_app2.o.comp

app1.o.nm :	app1.o
	echo "% nm app1.o" > app1.o.nm
	nm app1.o >> app1.o.nm
	echo "% " >> app1.o.nm

combine_app1.o.nm :	combine_app1.o
	echo "% nm combine_app1.o" > combine_app1.o.nm
	nm combine_app1.o >> combine_app1.o.nm
	echo "% " >> combine_app1.o.nm

app2.o.nm :	app2.o
	echo "% nm app2.o" > app2.o.nm
	nm app2.o >> app2.o.nm
	echo "% " >> app2.o.nm

combine_app2.o.nm :	combine_app2.o
	echo "% nm combine_app2.o" > combine_app2.o.nm
	nm combine_app2.o >> combine_app2.o.nm
	echo "% " >> combine_app2.o.nm

combine :	combine.c app1 app2 combine_app1.o combine_app2.o
	echo "% gcc combine.c combine_app1.o combine_app2.o -Wall -o combine" >> combine.comp
	gcc combine.c combine_app1.o combine_app2.o -Wall -o combine
	echo "% rm app1" >> combine.comp
	rm app1
	echo "% rm app2" >> combine.comp
	rm app2
	echo "% ln -s combine app1" >> combine.comp
	ln -s combine app1
	echo "% ln -s combine app2" >> combine.comp
	ln -s combine app2
	echo "% ls -l combine app?" >> combine.comp
	ls -l combine app? >> combine.comp

combine.exec :	combine
	echo "% ./combine" > combine.exec
	(./combine 2>&1 | cat) >> combine.exec &
	sleep 1
	echo "% " >> combine.exec
	echo "% ./app1" >> combine.exec
	(./app1 2>&1 | cat) >> combine.exec &
	sleep 1
	echo "% " >> combine.exec
	echo "% ./app2" >> combine.exec
	(./app2 2>&1 | cat) >> combine.exec &
	sleep 1

clean :
	rm -f $(OBJS) *.comp

