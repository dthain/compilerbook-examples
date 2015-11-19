
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

%.s: %.cminor
	echo "*** Make sure to put cminor in your PATH! ***"
	cminor -codegen $< $@

clean:
	rm -f *.o *.s *~ fibonnacci bounce maze

