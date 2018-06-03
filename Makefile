CFLAGS = -g -O2 -std=gnu99 -Wall -pedantic -funit-at-a-time

all: clean swap-test

swap-test: \
    swap-test.c

types:
	@echo "Support types:"
	@grep __builtin_types_compatible_p fswap.h | awk -F"," '{ print substr($$2,0,length($$2)-1) }'

doc:
	@(cat docs/Doxyfile ; echo "GENERATE_HTML=NO" ; echo "GENERATE_XML=NO") | doxygen -
	@echo "create documentation, see /docs/man/man3"

clean:
	@rm -f swap-test
	@rm -f swap-test.o
