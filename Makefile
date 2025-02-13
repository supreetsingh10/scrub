CC := gcc
CFLAGS := -g3 -fsanitize=address -gdwarf-2

scrub: buffer.o keypresses.o global.o scrub.o render.o
	$(CC) $(CFLAGS) -o scrub buffer.o keypresses.o scrub.o global.o render.o

scrub.o: scrub.c
	$(CC) $(CFLAGS) -c scrub.c

buffer.o: buffer.c
	$(CC) $(CFLAGS) -c buffer.c

keypresses.o: keypresses.c
	$(CC) $(CFLAGS) -c keypresses.c

global.o: global.c
	$(CC) $(CFLAGS) -c global.c

render.o: render.c
	$(CC) $(CFLAGS) -c render.c

clean: 
	rm scrub

