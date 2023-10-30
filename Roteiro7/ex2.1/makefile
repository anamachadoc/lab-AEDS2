CC=gcc
CFLAGS=-I.
DEPS = mfaixa.h menu.h
OBJ = main.o mfaixa.o menu.o
EXEC = exec

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(EXEC) *.o *~ core