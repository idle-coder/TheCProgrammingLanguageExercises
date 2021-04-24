

CC=gcc
CFLAGS=
SRCDIR=src
BINDIR=bin
SRCS=$(wildcard $(SRCDIR)/*)
BINS=$(patsubst $(SRCDIR)/%,$(BINDIR)/%,$(SRCS))
TARGS=$(basename $(notdir $(wildcard $(SRCDIR)/chapter-?/*.c)))

all: $(TARGS)

$(TARGS): %: $(SRCS)/%.c
	$(CC) $(CFLAGS) -o $(BINS)/$@ $<

clean:
	$(RM) -r $(CURDIR)/$(BINS)/*

print-%:
	@echo '$*=$($*)'
