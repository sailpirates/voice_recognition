all: libnumbers.a

libnumbers.a: OInteger.o
	ar rcs $@ $^

%.o: %.cpp
	gcc -g -c -o $@ -I.. -I../SalmonEye $^

%.o: %.c
	gcc -g -c -o $@ -I.. -I../SalmonEye $^
