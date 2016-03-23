CC = gcc
CPPFLAGS = -Wall

FILE_SUFFIX = c

SRCS := $(wildcard *.$(FILE_SUFFIX))
EXES := $(patsubst %.$(FILE_SUFFIX),%,$(SRCS))

all:$(EXES)

$(EXES): % : %.$(FILE_SUFFIX)
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(EXES)
