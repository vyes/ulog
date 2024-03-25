CC = $(CROSS_COMPILE)gcc
AR = $(CROSS_COMPILE)ar
RANLIB = $(CROSS_COMPILE)ranlib

TARGET=lib$(shell basename `pwd`).a
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:%.c=%.o)

#INCLUDES+=-I../
CFLAGS+=-Wall -O3

all: $(TARGET)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(CFLAGS) $(SOURCES)

$(TARGET): $(OBJECTS)
	$(AR) rcs $(TARGET) $(OBJECTS)
	$(RANLIB) $(TARGET)

clean:
	$(RM) $(OBJECTS) $(TARGET)

.PHONY: all clean
