CC=gcc
CFLAGS=-I.
DEPS = ordenacao.h leituraValores.h compara.h
OBJ = main.o 
EXEC = exec

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(EXEC) *.o *~ core