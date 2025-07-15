#!/bin/bash

bin/test
status=$?

if [ -d src/force-cover ]; then

    llvm-profdata merge default.profraw -o default.profdata
    llvm-cov show bin/test -instr-profile=default.profdata src/marray > coverage.txt
    python3 src/force-cover/fix_coverage.py coverage.txt

fi

exit $status
