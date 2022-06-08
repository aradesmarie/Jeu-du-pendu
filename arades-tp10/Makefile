srcdir = ./src/
bindir = ./bin/
docdir = ./doc/
savedir = ./save/


CC = gcc -Wall
RM = clean
SRC = $(wildcard $(srcdir)*.c)
HEAD = $(wildcard $(srcdir)*.c)
OBJ = $(subst $(srcdir), $(bindir), $(SRC:.c=.o))
PROG = ./bin/exec

$(PROG) : $(OBJ)
	@$(CC) $^ -o $@ -lm

$(bindir)main.o: $(srcdir)main.c
	$(CC) -c $^ -o $@

$(bindir)%.o: $(srcdir)%.c $(srcdir)%.h
	$(CC) -c $< -o $(@)

.PHONY: clean doxy
clean:
	rm -f $(OBJ)

doxy:
	doxygen Doxyfile