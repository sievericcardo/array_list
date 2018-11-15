OUTPUT= build/arraylist.out
OUTPUT_TEST= build/arraylist_test.out

C= gcc
CFLAGS= -std=c99 -pedantic -Werror

INPUT= $(C) $(CFLAGS) arraylist.c usage/main.c -o $(OUTPUT)

INPUT_TEST= $(C) $(CFLAGS) arraylist.c test/arraylist_tests.c test/Unity/unity.c -o $(OUTPUT_TEST)

.PHONY: clean

all:
	$(INPUT) && $(INPUT_TEST)

clean:
	rm -rf build/* out.txt

run:
	./$(OUTPUT)

test:
	./$(OUTPUT_TEST)
