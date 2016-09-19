#!/bin/sh
make clean > /dev/null;
rm -f *html > /dev/null;

# Compile and run:
make > /dev/null;

./templateTypes

xcrun llvm-profdata merge -o templateTypes.profdata default.profraw
xcrun llvm-cov report ./templateTypes -instr-profile=templateTypes.profdata -use-color
xcrun llvm-cov show ./templateTypes -instr-profile=templateTypes.profdata -use-color
