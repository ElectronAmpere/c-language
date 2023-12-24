CC = clang
CFLAGS = -std=C99 -pedantic -D_XOPEN_SOURCE=600 -Wall -Werror -g
RM = rm -f
SRC := $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

.PHONY: all clean

all: $(PROGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(PROGS)