# Lab 6 - Makefile
#
# Re-write your solutions to Lab 1 and Lab 3 to use The Better String Library
#
# You may use lab01.c and lab03.c from ../solutions at a 10% penalty
#
# This Makefile expects your code to be in files named lab01.c and lab03.c
#
# Do not change this Makefile; submit your updated C code to Dropbox.
#

CC=gcc
INCLUDES=-I$(DEBUGDIR) -I$(BSTRDIR)
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option $(INCLUDES)

LAB01PROG = lab01
LAB01SRCS = lab01.c
LAB01OBJS = $(LAB01SRCS:.c=.o)

LAB03PROG = lab03
LAB03SRCS = lab03.c
LAB03OBJS = $(LAB03SRCS:.c=.o)

PROGS = $(LAB01PROG) $(LAB03PROG)
SRCS = $(LAB01SRCS) $(LAB03SRCS)
OBJS = $(SRCS:.c=.o)

BSTRDIR = ../bstrlib
BSTRSRCS = $(BSTRDIR)/bstrlib.c $(BSTRDIR)/bstraux.c
BSTROBJS = $(BSTRSRCS:.c=.o)
BSTRFLAGS = -O3 -Wall -pedantic -ansi -s

DEBUGDIR = ../debug

all: $(PROGS)

lab01: $(LAB01OBJS) $(BSTROBJS)
	$(CC) $(LAB01OBJS) $(BSTROBJS) -o $(LAB01PROG)

lab03: $(LAB03OBJS) $(BSTROBJS)
	$(CC) $(LAB03OBJS) $(BSTROBJS) -o $(LAB03PROG)

lab01.o: lab01.c

lab03.o: lab03.c

$(BSTRDIR)/%.o: $(BSTRDIR)/%.c $(BSTRDIR)/%.h
	$(CC) $(BSTRFLAGS) -c $< -o $@

clean:
	rm -f core $(PROGS) $(OBJS)

distclean: clean
	rm -f $(BSTROBJS)

