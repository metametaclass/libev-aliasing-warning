CFLAGS      += -Wall -O2 -g
CPPFLAGS    +=
LDFLAGS     +=

test_alias: test_alias.o

#%.o: %.c Makefile
#	    $(CC) -Wp,-MMD,.$<.d -o $@ -c $(CFLAGS) $<

clean:
	rm *.o test_alias
