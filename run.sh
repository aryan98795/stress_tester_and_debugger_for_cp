#!/bin/bash

src="$1"

if [[ -z "$src" ]]; then
  echo "Usage: ./run.sh <file.cpp|file.py>"
  exit 1
fi

ext="${src##*.}"
infile="input.txt"
outfile="output.txt"
errfile="error.txt"

case "$ext" in
  cpp)
    g++ "$src" -o run && ./run < "$infile" > "$outfile" 2> "$errfile"
    ;;
  py)
    python3 "$src" < "$infile" > "$outfile" 2> "$errfile"
    ;;
  *)
    echo "Unsupported file type: .$ext"
    exit 1
    ;;
esac
