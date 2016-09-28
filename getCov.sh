#!/bin/sh

# Clean 
make clean > /dev/null;
rm -f *.html > /dev/null;

# Compile and run:
make > /dev/null;
./templateTypes;

/usr/local/bin/gcovr -r . -b --html --html-details -o coverage.html -d;
