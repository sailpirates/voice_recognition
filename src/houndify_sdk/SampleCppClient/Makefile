all: sample_hound_cpp_client

sample_hound_cpp_client: sample_hound_driver.o sample_hound_driver_system_dependent_standard.o sample_slim_cpp_client.o
	g++ -o $@ $^ -L../HoundRequester -lhoundrequester -L../GoldenRetriever -lGoldenRetriever -L../HoundJSON -lhoundjson -L../JSON -ljson_library -L../Numbers -lnumbers -L../SalmonEye -lSalmonEye -L../c_foundations -lc_foundations -lssl -ldl -lcrypto

%.o: %.cpp
	gcc -g -c -o $@ -I.. -I../HoundRequester -I../HoundJSON -I../JSON -I../Numbers -I../SalmonEye -I../c_foundations -I../GoldenRetriever -I../HTTP -I../ReferenceCounting $^

%.o: %.c
	gcc -g -c -o $@ -I.. -I../HoundRequester -I../HoundJSON -I../JSON -I../Numbers -I../SalmonEye -I../c_foundations -I../GoldenRetriever -I../HTTP -I../ReferenceCounting $^
