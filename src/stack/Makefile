TARGET = stack_sample
CFLAGS += -O -Wall

all :	$(TARGET)

stack_sample :	stack_sample.c
	echo "% gcc -S stack_sample.c -Wall" > stack_sample.comp
	gcc -S stack_sample.c -Wall >> stack_sample.comp 2>&1
	echo "% " >> stack_sample.comp

clean :
	rm -f $(TARGET) *.o *.comp
