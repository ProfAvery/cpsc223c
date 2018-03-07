CC=gcc
INCLUDES=-I$(DEBUGDIR) -I$(BSTRDIR)
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option $(INCLUDES)

LAB1PROG = lab1
LAB1SRCS = lab1.c
LAB1OBJS = $(LAB1SRCS:.c=.o)

LAB3PROG = lab3
LAB3SRCS = lab3.c
LAB3OBJS = $(LAB3SRCS:.c=.o)

PROGS = $(LAB1PROG) $(LAB3PROG)
SRCS = $(LAB1SRCS) $(LAB3SRCS)
OBJS = $(SRCS:.c=.o)

BSTRDIR = ../bstrlib
BSTRSRCS = $(BSTRDIR)/bstrlib.c $(BSTRDIR)/bstraux.c
BSTROBJS = $(BSTRSRCS:.c=.o)
BSTRFLAGS = -O3 -Wall -pedantic -ansi -s

DEBUGDIR = ../debug

all: $(PROGS)

lab1: $(LAB1OBJS) $(BSTROBJS)
	$(CC) $(LAB1OBJS) $(BSTROBJS) -o $(LAB1PROG)

lab3: $(LAB3OBJS) $(BSTROBJS)
	$(CC) $(LAB3OBJS) $(BSTROBJS) -o $(LAB3PROG)

lab1.o: lab1.c

lab3.o: lab3.c

$(BSTRDIR)/%.o: $(BSTRDIR)/%.c $(BSTRDIR)/%.h
	$(CC) $(BSTRFLAGS) -c $< -o $@

clean:
	rm -f core $(PROGS) $(OBJS)

distclean: clean
	rm -f $(BSTROBJS)

