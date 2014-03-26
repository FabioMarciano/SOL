#
# FILE: MAKEFILE
# DATE: 2014-02-25
# AUTHOR: FABIO MARCIANO
#

USRDIR = ~/
INCDIR = $(USRDIR)
LIBLBL = SOL
PREFIX = mod
CC = gcc
CFLAGS = -fPIC -Wall -I $(INCDIR) -c -o
DFLAGS = -shared -Wl,-soname,lib$(LIBLBL).so -o lib$(LIBLBL).so
LDFLAGS=
EXECUTABLE = $(LIBLBL)
SOURCES = $(PREFIX).node.c $(PREFIX).string.c $(PREFIX).crypt.c $(PREFIX).http.c $(PREFIX).db.c $(LIBLBL).c
OBJECTS = $(SOURCES:.c=.o)
PACKAGE = ar rs

all: purge $(OBJECTS) $(EXECUTABLE) clean

$(EXECUTABLE):
	@$(PACKAGE) $@.a $@.o $(SOURCES:.c=.o) > /dev/null 2> /dev/null
	@$(CC) $(DFLAGS) $(SOURCES:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) $@ $<
	@if [ -f '$@' ] ; then tput setaf 2 && echo -n " [OK]\t" && tput setaf 3 && echo $@; else tput setaf 1 && echo -n " [NO]\t" && tput setaf 3 && echo $@; fi;
	@tput sgr0

purge:
	@rm -f *.a *.so

clean:
	@rm -f *.o
