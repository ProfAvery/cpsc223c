CC=gcc
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option

PROG = phonebook
SRCS = main.c commands.c faculty.c
OBJS = $(SRCS:.c=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o: main.c commands.h faculty.h

commands.o: commands.c commands.h faculty.h

faculty.o: faculty.c faculty.h

clean:
	rm -f core $(PROG) $(OBJS)

