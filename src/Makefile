DIRS += ar binary combine const constructor continue core \
	ctors edata elfread elfsamp hello \
	initialize layer linker loader pointer rasm \
	section setjmp shared stack values weak

all :
	for d in ${DIRS}; do cd $$d ; $(MAKE)       ; cd .. ; done

clean :
	for d in ${DIRS}; do cd $$d ; $(MAKE) clean ; cd .. ; done
