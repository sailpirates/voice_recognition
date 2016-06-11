all: libc_foundations.a

libc_foundations.a: buffer_print.o diagnostic.o memory_allocation.o memory_allocation_test.o merge_dense_integer_arrays.o print_formatting.o string_aam.o string_index.o trace.o bytewise_hex_pointer_conversion.o division_floating_point_conversion.o floating_point_output.o sprintf_floating_point_conversion.o sprintf_pointer_conversion.o
	ar rcs $@ $^

%.o: %.cpp
	gcc -g -c -o $@ -I.. $^

%.o: %.c
	gcc -g -c -o $@ -I.. $^

%.o: print_formatting/%.cpp
	gcc -g -c -o $@ -I. -I.. $^

%.o: print_formatting/%.c
	gcc -g -c -o $@ -I. -I.. $^
