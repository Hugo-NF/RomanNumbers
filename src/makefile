PRINCIPAL=test_roman_numbers

IDIR =../include
CC=g++
EXT = c
CFLAGS=-Wall -g -fprofile-arcs -ftest-coverage -I $(IDIR)

GCOVDIR=gcov_files
ODIR=obj
LDIR =../lib

LIBS=-lm /usr/lib/libgtest.a -lgtest -lpthread

_DEPS = module.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(PRINCIPAL).o module.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.$(EXT) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PRINCIPAL): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/* *~ core $(INCDIR)/*~ 

.PHONY: reset
reset:
	make clean
	rm -f teste
	rm -f $(GCOVDIR)/*
	rm -f ../Valores.txt

.PHONY: mv_gcov_files
mv_gcov_files:
	mv $(ODIR)/*.gcda $(GCOVDIR)
	mv $(ODIR)/*.gcno $(GCOVDIR)
	cp $(PRINCIPAL).$(EXT) $(GCOVDIR)
	cp module.c $(GCOVDIR)
