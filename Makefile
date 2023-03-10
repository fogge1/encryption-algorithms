CC=gcc

CPPFLAGS?=
CPPFLAGS+=-Wall -Wextra -MD -std=c99

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
SRC_MAKE=$(SRC:.c=.d)
BIN=encrypt


all: $(BIN)

%.o : %.c 
	@$(CC) -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

$(BIN): $(OBJ)
	@$(CC) -o $@ $(LDFLAGS) $(OBJ)

-include $(SRC_MAKE)

