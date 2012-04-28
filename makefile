CFLAGS      += -Wall -O2 -g
CPPFLAGS    +=
LDFLAGS     +=

test_alias: test_alias.o

clean:
	rm *.o test_alias
