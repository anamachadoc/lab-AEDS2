CC=gcc
CFLAGS=-I.
DEPS = menu.h conjunto.h
OBJ = main.o menu.o conjunto.o
EXEC = exec

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(EXEC) *.o *~ core