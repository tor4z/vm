CC 		= gcc
CFLAGS 	= -Wall
TARGET 	= VM
CFILES 	= $(wildcard ./vm/*.c)
OBJS 	= $(patsubst %.c, %.o, $(CFILES)) 

vpath = vm

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(CFILES)


.PHONY: clean
clean:
	-rm -f $(OBJS) $(TARGET)