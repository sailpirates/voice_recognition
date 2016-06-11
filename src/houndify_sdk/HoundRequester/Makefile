all: libhoundrequester.a

libhoundrequester.a: HoundRequester.o HoundCloudRequester.o HoundSharedDoneFlagSingleThreaded.o HoundHMACSHA256.o HoundUnixTimeStampFromANSICTime.o build_info.o
	ar rcs $@ $^

%.o: %.cpp
	gcc -g -c -o $@ -I.. -I../GoldenRetriever -I../HoundJSON -I../JSON -I../SalmonEye -I../c_foundations -I../HTTP -I../Numbers -I../Common -I../ReferenceCounting $^

%.o: %.c
	gcc -g -c -o $@ -I.. -I../GoldenRetriever -I../HoundJSON -I../JSON -I../SalmonEye -I../c_foundations -I../HTTP -I../Numbers -I../Common -I../ReferenceCounting $^
