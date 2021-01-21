all: lib main


libmyCalc/add.o: libmyCalc/addition.c
	gcc -c -o $@ $<

libmyCalc/sub.o: libmyCalc/subtraction.c
	gcc -c -o $@ $<

libmyCalc/mul.o: libmyCalc/multiplication.c
	gcc -c -o $@ $<

libmyCalc/div.o: libmyCalc/division.c
	gcc -c -o $@ $<

lib: libmyCalc/add.o libmyCalc/sub.o libmyCalc/mul.o libmyCalc/div.o
	ar rc libmyCalc.a $^

main: lib
	gcc main.c -L . -lmyCalc --static -o main.out

clean:
	rm -rf libmyCalc/*.o main.out 