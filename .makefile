all: %.c
	$(CC) $(CFLAGS) $^

clean:
	$(RM) $(TARGET)

CC=gcc
CFLAGS=-std=c99 -o $@.out