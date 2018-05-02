CC=gcc
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option

test: dealership
	./dealership

dealership: main.o automobile.o car.o truck.o suv.o
	$(CC) main.o automobile.o car.o truck.o suv.o -o dealership

main.o: main.c automobile.h car.h
	$(CC) $(CFLAGS) -c main.c -o main.o

automobile.o: automobile.c automobile.h
	$(CC) $(CFLAGS) -c automobile.c -o automobile.o

car.o: car.c automobile.h car.h
	$(CC) $(CFLAGS) -c car.c -o car.o

truck.o: truck.c automobile.h truck.h
	$(CC) $(CFLAGS) -c truck.c -o truck.o

suv.o: suv.c automobile.h suv.h
	$(CC) $(CFLAGS) -c suv.c -o suv.o

clean:
	rm -f core main.o automobile.o car.o truck.o suv.o dealership

