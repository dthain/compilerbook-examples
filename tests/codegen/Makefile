
all: bounce fibonnacci maze

bounce: bounce.o library.o gfx.o
	gcc $^ -o $@ -lX11 -lm

fibonnacci: fibonnacci.o library.o
	gcc $^ -o $@

maze: maze.o library.o
	gcc $^ -o $@

%.o: %.s
	gcc -c $< -o $@ -g

%.o: %.c
	gcc -c $< -o $@ -g

%.s: %.bminor
	echo "*** Make sure to put bminor in your PATH! ***"
	bminor -codegen $< $@

clean:
	rm -f *.o *.s *~ fibonnacci bounce maze

