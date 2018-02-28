OUT= $@
IN= $(OUT:out=c)

CC=gcc
CFLAGS=-std=c99 -o $(OUT)

%.out: %.c
	$(CC) $(IN) $(CFLAGS)
	echo Build Successful

clean:
	rm *.out
	echo Removed all executables