all: libjson_library.a

libjson_library.a: JSONRep.o JSONWriter.o JSONParse.o JSONIncrementalParse.o JSONCheckingHandler.o JSONBooleanGenerator.o JSONNullGenerator.o JSONStringGenerator.o JSONNumberGenerator.o JSONIntegerGenerator.o JSONDoubleGenerator.o JSONObjectGenerator.o JSONArrayGenerator.o JSONParallelGenerator.o
	ar rcs $@ $^

%.o: %.cpp
	gcc -g -c -o $@ -I.. -I../SalmonEye -I../c_foundations $^

%.o: %.c
	gcc -g -c -o $@ -I.. -I../SalmonEye -I../c_foundations $^
