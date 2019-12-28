#!/bin/bash

programname=$0

function usage {
    echo "usage: $programname [-abch] [-f infile] [-o outfile]"
    echo "  -a      turn on feature a"
    echo "  -b      turn on feature b"
    echo "  -c      turn on feature c"
    echo "  -h      display help"
    echo "  -f infile   specify input file infile"
    echo "  -o outfile  specify output file outfile"
    exit 1
}

usage
