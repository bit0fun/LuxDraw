CC=gcc
LDFLAGS= -l X11
CFLAGS= -g
PRGNAME=window

SRC_DIR= ./src

SRC= $(wildcard $(SRC_DIR)/*.c)
OBJ= $(SRC:.c=.o)
INC= debug.h
DEP= $(OBJ:.o=.d)

all: $(PRGNAME)


$(PRGNAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

-include $(DEP)

%.d: %.c
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@
		
.PHONY: clean
clean:
	-rm -f $(OBJ)
	-rm -f $(DEP)
	-rm -f $(PRGNAME)

