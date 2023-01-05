OBJS=	layer_sub1.o layer_sub2.o liblayer.a liblayer_local.a \
	layer_lib.o layer_lib_local.o layer.o layer2.o \
	layer alayer alayer_local alayer2_local \
	olayer olayer_local olayer2_local \
	layer.exec alayer.exec alayer_local.exec alayer2_local.exec \
	olayer.exec olayer_local.exec olayer2_local.exec \
	liblayer.a.nm liblayer_local.a.nm layer_lib.o.nm layer_lib_local.o.nm \
	layer_lib2.o.comp

all :	$(OBJS)

layer_sub1.o :	layer_sub1.c
	echo "% gcc -c layer_sub1.c -Wall" > layer_sub1.o.comp
	gcc -c layer_sub1.c -Wall >> layer_sub1.o.comp 2>&1
#	echo "% " >> layer_sub1.o.comp

layer_sub2.o :	layer_sub2.c
	echo "% gcc -c layer_sub2.c -Wall" > layer_sub2.o.comp
	gcc -c layer_sub2.c -Wall >> layer_sub2.o.comp 2>&1
#	echo "% " >> layer_sub2.o.comp

liblayer.a :	layer_sub1.o layer_sub2.o
	echo "% ar ruc liblayer.a layer_sub1.o layer_sub2.o" \
		> liblayer.a.comp
	ar ruc liblayer.a layer_sub1.o layer_sub2.o >> liblayer.a.comp 2>&1
	echo "% " >> liblayer.a.comp

liblayer_local.a :	liblayer.a
	echo "% objcopy --localize-symbol=num liblayer.a liblayer_local.a" \
		> liblayer_local.a.comp
	objcopy --localize-symbol=num liblayer.a liblayer_local.a \
		>> liblayer_local.a.comp 2>&1
	echo "% " >> liblayer_local.a.comp

layer_lib.o :	layer_sub1.o layer_sub2.o
	echo "% ld -r layer_sub1.o layer_sub2.o -o layer_lib.o" \
		> layer_lib.o.comp
	ld -r layer_sub1.o layer_sub2.o -o layer_lib.o >> layer_lib.o.comp 2>&1
	echo "% " >> layer_lib.o.comp

layer_lib_local.o :	layer_lib.o
	echo "% objcopy --localize-symbol=num layer_lib.o layer_lib_local.o" \
		> layer_lib_local.o.comp
	objcopy --localize-symbol=num layer_lib.o layer_lib_local.o \
		>> layer_lib_local.o.comp 2>&1
	echo "% " >> layer_lib_local.o.comp

layer_lib2.o.comp :	layer_sub1.c
	echo "% cp layer_sub1.c layer_sub3.c" > layer_lib2.o.comp
	cp layer_sub1.c layer_sub3.c >> layer_lib2.o.comp
	echo "% gcc -c layer_sub3.c" >> layer_lib2.o.comp
	gcc -c layer_sub3.c >> layer_lib2.o.comp
	echo "% ld -r layer_sub1.o layer_sub3.o -o layer_lib2.o" \
		>> layer_lib2.o.comp
	(ld -r layer_sub1.o layer_sub3.o -o layer_lib2.o 2>&1 | cat) \
		>> layer_lib2.o.comp &
	sleep 1
	echo "% " >> layer_lib2.o.comp

layer.o :	layer.c
	echo "% gcc -c layer.c -Wall" > layer.o.comp
	gcc -c layer.c -Wall >> layer.o.comp 2>&1
#	echo "% " >> layer.o.comp

layer2.o :	layer2.c
	echo "% gcc -c layer2.c -Wall" > layer2.o.comp
	gcc -c layer2.c -Wall >> layer2.o.comp 2>&1
#	echo "% " >> layer2.o.comp

layer :	layer.o layer_sub1.o layer_sub2.o
	echo "% gcc layer.o layer_sub1.o layer_sub2.o -o layer" > layer.comp
	gcc layer.o layer_sub1.o layer_sub2.o -o layer >> layer.comp 2>&1
	echo "% " >> layer.comp

alayer :	layer.o liblayer.a
	echo "% gcc layer.o -o alayer -L. -llayer" > alayer.comp
	gcc layer.o -o alayer -L. -llayer >> alayer.comp 2>&1
	echo "% " >> alayer.comp

alayer_local :	layer.o liblayer_local.a
	echo "% gcc layer.o -o alayer_local -L. -llayer_local" \
		> alayer_local.comp
	(gcc layer.o -o alayer_local -L. -llayer_local 2>&1 | cat) \
		>> alayer_local.comp &
	sleep 1
	echo "% " >> alayer_local.comp

alayer2_local :	layer2.o liblayer_local.a
	echo "% gcc layer2.o -o alayer2_local -L. -llayer_local" \
		> alayer2_local.comp
	(gcc layer2.o -o alayer2_local -L. -llayer_local 2>&1 | cat) \
		>> alayer2_local.comp &
	sleep 1
	echo "% " >> alayer2_local.comp

olayer :	layer.o layer_lib.o
	echo "% gcc layer.o layer_lib.o -o olayer" > olayer.comp
	gcc layer.o layer_lib.o -o olayer >> olayer.comp 2>&1
	echo "% " >> olayer.comp

olayer_local :	layer.o layer_lib_local.o
	echo "% gcc layer.o layer_lib_local.o -o olayer_local" \
		> olayer_local.comp
	(gcc layer.o layer_lib_local.o -o olayer_local 2>&1 | cat) \
		>> olayer_local.comp &
	sleep 1
	echo "% " >> olayer_local.comp

olayer2_local :	layer2.o layer_lib_local.o
	echo "% gcc layer2.o layer_lib_local.o -o olayer2_local" \
		> olayer2_local.comp
	gcc layer2.o layer_lib_local.o -o olayer2_local >> olayer2_local.comp &
#	echo "% " >> olayer2_local.comp

layer.exec :	layer
	echo "% ./layer" > layer.exec
	(./layer 2>&1 | cat) >> layer.exec &
	sleep 1
	echo "% " >> layer.exec
	rm -f layer.core

alayer.exec :	alayer
	echo "% ./alayer" > alayer.exec
	(./alayer 2>&1 | cat) >> alayer.exec &
	sleep 1
	echo "% " >> alayer.exec
	rm -f alayer.core

alayer_local.exec :	alayer_local
	echo "% ./alayer_local" > alayer_local.exec
	(./alayer_local 2>&1 | cat) >> alayer_local.exec &
	sleep 1
	echo "% " >> alayer_local.exec
	rm -f alayer_local.core

alayer2_local.exec :	alayer2_local
	echo "% ./alayer2_local" > alayer2_local.exec
	(./alayer2_local 2>&1 | cat) >> alayer2_local.exec &
	sleep 1
	echo "% " >> alayer2_local.exec
	rm -f alayer2_local.core

olayer.exec :	olayer
	echo "% ./olayer" > olayer.exec
	(./olayer 2>&1 | cat) >> olayer.exec &
	sleep 1
	echo "% " >> olayer.exec
	rm -f olayer.core

olayer_local.exec :	olayer_local
	echo "% ./olayer_local" > olayer_local.exec
	(./olayer_local 2>&1 | cat) >> olayer_local.exec &
	sleep 1
	echo "% " >> olayer_local.exec
	rm -f olayer_local.core

olayer2_local.exec :	olayer2_local
	echo "% ./olayer2_local" > olayer2_local.exec
	(./olayer2_local 2>&1 | cat) >> olayer2_local.exec &
	sleep 1
	echo "% " >> olayer2_local.exec
	rm -f olayer2_local.core

liblayer.a.nm :	liblayer.a
	echo "% nm liblayer.a" > liblayer.a.nm
	nm liblayer.a >> liblayer.a.nm
	echo "% " >> liblayer.a.nm

liblayer_local.a.nm :	liblayer_local.a
	echo "% nm liblayer_local.a" > liblayer_local.a.nm
	nm liblayer_local.a >> liblayer_local.a.nm
	echo "% " >> liblayer_local.a.nm

layer_lib.o.nm :	layer_lib.o
	echo "% nm layer_lib.o" > layer_lib.o.nm
	nm layer_lib.o >> layer_lib.o.nm
	echo "% " >> layer_lib.o.nm

layer_lib_local.o.nm :	layer_lib_local.o
	echo "% nm layer_lib_local.o" > layer_lib_local.o.nm
	nm layer_lib_local.o >> layer_lib_local.o.nm
	echo "% " >> layer_lib_local.o.nm

clean :
	rm -f $(OBJS) *.comp

