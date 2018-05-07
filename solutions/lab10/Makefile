CC=gcc
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option `pkg-config --cflags glib-2.0`
LDFLAGS = `pkg-config --libs glib-2.0`

PROG = freq
SRCS = freq.c
OBJS = $(SRCS:.c=.o)
INPUT = file.txt

test: $(PROG) file.txt
	./$(PROG) file.txt

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LDFLAGS)

freq.o: freq.c

clean:
	rm -f core $(PROG) $(OBJS)

