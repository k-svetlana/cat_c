CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
TARGET = cat

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(FLAGS) $(TARGET).c -o $(TARGET)

clang:
	clang-format -i *.c *.h

test: all
	bash cat.sh > test_log.txt

clean:
	rm -f $(TARGET) *.o

rebuild: clean all
