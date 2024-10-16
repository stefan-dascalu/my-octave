CC=gcc
CFLAGS=-Wall -Wextra -std=c99

TARGETS = my_octave

build: $(TARGETS)

my_octave: my_octave.c help.c help.h
	$(CC) $(CFLAGS) my_octave.c help.c help.h -o my_octave

pack:
	zip -FSr 321CA_Dascalu_Stefan_Nicolae_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
