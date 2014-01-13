CC = g++
CPPFLAGS = -Wall

FILE_SUFFIX = cpp

SRCS := $(wildcard *.$(FILE_SUFFIX))
EXES := $(patsubst %.$(FILE_SUFFIX),%,$(SRCS))

all:$(EXES)

$(EXES): % : %.$(FILE_SUFFIX)
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(EXES)
