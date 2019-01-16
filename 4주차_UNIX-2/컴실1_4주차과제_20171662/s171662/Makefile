OBJECTS = main.o count.o print.o
SRCS = main.c count.c print.c

CC = gcc
CFLAGS = -g -c

TARGET = Starwars

$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
main.o : header.h main.c
count.o : header.h count.c
print.o : header.h print.c
