#!/bin/bash
  gcc -Wall -pedantic 3D_vector.c -o 3D_vektor -lm
  if [ $? -ne 0 ]; then
    echo "Kompilace selhala"
    exit 1
  fi
  for f in *.in; do
    echo "--- Test $f ---"
    ./main < "$f" > "${f%.in}.out"
    cat "${f%.in}.out"
    echo ""
  done