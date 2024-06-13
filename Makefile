IDIR=include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=src/obj

_DEPS = board.h piece.h player.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = board.o piece.o player.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cchess: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f @(ODIR)/* .o *~ core $(INCFIR)/*~