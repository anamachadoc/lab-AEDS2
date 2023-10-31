CC=gcc
CFLAGS=-I.
DEPS = ABP.h menu.h
OBJ = main.o ABP.o menu.o
EXEC = exec

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(EXEC) *.o *~ core