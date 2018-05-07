CC=gcc
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option

MKPROG = mkphone
MKSRCS = mkphone.c utils.c faculty.c
MKOBJS = $(MKSRCS:.c=.o)

LSPROG = lsphone
LSSRCS = lsphone.c utils.c faculty.c
LSOBJS = $(LSSRCS:.c=.o)

PHPROG = phone
PHSRCS = phone.c commands.c utils.c faculty.c
PHOBJS = $(PHSRCS:.c=.o)

PROGS = $(MKPROG) $(LSPROG) $(PHPROG)

all: $(PROGS)

$(LSPROG): $(LSOBJS)
	$(CC) $(LSOBJS) -o $(LSPROG)

$(MKPROG): $(MKOBJS)
	$(CC) $(MKOBJS) -o $(MKPROG)

$(PHPROG): $(PHOBJS)
	$(CC) $(PHOBJS) -o $(PHPROG)

mkphone.o: mkphone.c utils.h faculty.h

lsphone.o: lsphone.c utils.h faculty.h

phone.o: phone.c commands.h utils.h faculty.h

clean:
	rm -f core $(PROGS) *.o *.bin

