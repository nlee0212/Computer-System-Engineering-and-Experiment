OBJECTS = main.o String_Manipulation.o Output.o
SRCS = main.cpp String_Manipulation.cpp Output.cpp

CC = g++
CFLAGS = -c

TARGET = main

$(TARGET) : $(OBJECTS) Header.h
	$(CC) -o $(TARGET) $(OBJECTS)

clean : 
	rm -rf $(OBJECTS) $(TARGET)

main.o : Header.h main.cpp
String_Manipulation.o : Header.h String_Manipulation.cpp
Output.o : Header.h Output.cpp
