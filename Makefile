OUTPUT= build/arraylist.out
OUTPUT_TEST= build/arraylist_test.out

C= gcc
CFLAGS= -std=c99 -pedantic -Werror

INPUT= $(C) $(CFLAGS) algorithms/insertion_sort.c usage/insertion_sort_usage.c -o $(OUTPUT)

INPUT_TEST= $(C) $(CFLAGS) arraylist.c test/arraylist_tests.c -o $(OUTPUT_TEST)

.PHONY: clean

all:
	$(INPUT) && $(INPUT_TEST)

clean:
	rm -rf build/* out.txt

run:
	./$(OUTPUT)

test:
	./$(OUTPUT_TEST)
