CC := gcc
CFLAGS := -g

scrub: buffer.o keypresses.o global.o scrub.o 
	$(CC) $(CFLAGS) -o scrub buffer.o keypresses.o scrub.o global.o
	rm *.o

scrub.o: scrub.c
	$(CC) $(CFLAGS) -c scrub.c

buffer.o: buffer.c
	$(CC) $(CFLAGS) -c buffer.c

keypresses.o: keypresses.c
	$(CC) $(CFLAGS) -c keypresses.c

global.o: global.c
	$(CC) $(CFLAGS) -c global.c

clean: 
	rm scrub


