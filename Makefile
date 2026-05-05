CC = gcc
CFLAGS = -Wall -Wextra -Werror 
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CHECK_FLAGS = -lcheck 

SRC = $(shell find . -name "*.c" ! -name "tests.c")
OBJ = $(SRC:.c=.o)

LIB = string.a
TEST_SRC = tests.c
HEADER = string.h

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)
	ranlib $(LIB)


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

test: clean $(LIB)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB) -o test $(CHECK_FLAGS)
	-./test


gcov_report: clean
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $(SRC)
	ar rcs $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_SRC) $(LIB) -o test $(CHECK_FLAGS)
	./test
	lcov -t "string" -o coverage.info -c -d .
	genhtml -o report coverage.info
	open report/index.html || xdg-open report/index.html || true

clean:
	rm -rf test report coverage.info *.a
	find . -name "*.o" -delete
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcov" -delete

rebuild: clean all

.PHONY: all test gcov_report clean rebuild
