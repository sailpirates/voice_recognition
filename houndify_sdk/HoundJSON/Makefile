all: libhoundjson.a

libhoundjson.a: BuildInfoJSON.o ClientMatchCommandJSON.o ClientMatchJSON.o ClientStateJSON.o ClientVerticalStateJSON.o CommandResultJSON.o ConversationStateJSON.o HoundMessageJSON.o HoundPartialTranscriptJSON.o HoundServerJSON.o HoundUpdateJSON.o RequestInfoJSON.o
	ar rcs $@ $^

%.o: %.cpp
	gcc -g -c -o $@ -I.. -I../JSON -I../SalmonEye -I../c_foundations -I../Numbers -I../Common -I../ReferenceCounting $^

%.o: %.c
	gcc -g -c -o $@ -I.. -I../JSON -I../SalmonEye -I../c_foundations -I../Numbers -I../Common -I../ReferenceCounting $^
