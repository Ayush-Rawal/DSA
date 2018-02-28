OUT= $@
IN= $(OUT:out=c)
LM=

CC=gcc
CFLAGS=-std=c99 -o $(OUT)

%.out: %.c
	$(CC) $(IN) $(CFLAGS) $(LM)
	echo Build Successful

clean:
	rm *.out
	echo Removed all executables