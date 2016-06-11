all: libGoldenRetriever.a

libGoldenRetriever.a: FetchLowLevelPosixSocketsNoScript.o Fetch.o FetchEnable.o
	ar rcs $@ $^

%.o: %.cpp
	gcc -g -c -o $@ -I.. -I../SalmonEye -I../c_foundations $^

%.o: %.c
	gcc -g -c -o $@ -I.. -I../SalmonEye -I../c_foundations $^
