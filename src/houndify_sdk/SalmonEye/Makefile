all: libSalmonEye.a

libSalmonEye.a: o_integer.o i_integer.o rational.o unicode.o source_location.o
	ar rcs $@ $^

%.o: %.cpp
	gcc -g -c -o $@ -I.. -I../c_foundations $^

%.o: %.c
	gcc -g -c -o $@ -I.. -I../c_foundations $^
