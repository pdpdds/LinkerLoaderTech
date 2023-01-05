TARGET ?= checksym
CC ?= gcc
CFLAGS += -O -Wall

all :	$(TARGET)

$(TARGET) :	$(TARGET).o
	$(CC) $(TARGET).o -o $(TARGET) -Wall

$(TARGET).o :	$(TARGET).c
	$(CC) -c $(TARGET).c $(CFLAGS)

clean :
	rm -f $(TARGET) *.o

