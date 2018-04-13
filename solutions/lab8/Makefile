CC=gcc
INCLUDES=-I$(DEBUGDIR) -I$(BSTRDIR)
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option $(INCLUDES) -D_POSIX_C_SOURCE=200801L

PROG = calculator
SRCS = main.c list.c commands.c
OBJS = $(SRCS:.c=.o)

BSTRDIR = ../../bstrlib
BSTRSRCS = $(BSTRDIR)/bstrlib.c $(BSTRDIR)/bstraux.c
BSTROBJS = $(BSTRSRCS:.c=.o)
BSTRFLAGS = -O3 -Wall -pedantic -ansi -s

DEBUGDIR = ../debug

all: $(PROG)

$(PROG): $(OBJS) $(BSTROBJS)
	$(CC) $(OBJS) $(BSTROBJS) -o $(PROG)

main.o: main.c list.h $(BSTRDIR)/bstrlib.h $(BSTRDIR)/bstraux.h

list.o: list.c list.h $(BSTRDIR)/bstrlib.h $(BSTRDIR)/bstraux.h

commands.o: commands.c commands.h list.h

$(BSTRDIR)/%.o: $(BSTRDIR)/%.c $(BSTRDIR)/%.h
	$(CC) $(BSTRFLAGS) -c $< -o $@

clean:
	rm -f core $(PROG) $(OBJS)

distclean: clean
	rm -f $(BSTROBJS)

