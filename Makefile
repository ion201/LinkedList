
CC = gcc
CFLAGS = -Wall -pedantic
OBJ = main.o LinkedList.o
OUT = main

DBGDIR = debug
DBGCFLAGS = -g
DBGOBJ = $(addprefix $(DBGDIR)/, $(OBJ))
DBGOUT = $(DBGDIR)/$(OUT)

RELDIR = release
RELCFLAGS = -O3
RELOBJ = $(addprefix $(RELDIR)/, $(OBJ))
RELOUT = $(RELDIR)/$(OUT)

.PHONY: all clean debug release

all: prep release

debug: $(DBGOUT)
$(DBGOUT): $(DBGOBJ)
	$(CC) $(CFLAGS) $(DBGCFLAGS) -o $@ $^
$(DBGDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(DBGCFLAGS) -o $@ $<

release: $(RELOUT)
$(RELOUT): $(RELOBJ)
	$(CC) $(CFLAGS) $(RELCFLAGS) -o $@ $^
$(RELDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(RELCFLAGS) -o $@ $<

prep:
	@mkdir -p $(DBGDIR) $(RELDIR)

remake: clean all

clean:
	rm -f $(RELOUT) $(RELOBJ) $(DBGOUT) $(DBGOBJ)

# "Simple" version:
#%.o: %.c
#	$(CC) -c -o $@ $< $(CFLAGS)

#main: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS)
