CC = gcc
CFLAGS = -std=c99 -pedantic-errors -g -Wall -Wextra -Werror -fsanitize=address,undefined

SRCS = $(filter-out bin/%, $(wildcard *.c */*.c))
BINS = $(patsubst %.c,bin/%,$(SRCS))
TARGET = bin/$(basename $(f))

.PHONY: all clean run

all: $(BINS)

bin/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf bin
