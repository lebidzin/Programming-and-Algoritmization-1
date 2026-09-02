#!/bin/bash

for in_file in quad/quad_*.in; do
  ref_file="${in_file%.in}.ref"
  
  # Pokud neexistuje specifický .ref, zkusí se 10x.ref pro chybové stavy
  if [ ! -f "$ref_file" ] && [[ "$in_file" =~ 10[0-9]\.in$ ]]; then
    ref_file="quad/quad_10x.ref"
  fi

  if [ -f "$ref_file" ]; then
    echo "=== Test $in_file ==="
    # Spuštění diffu a vypsání rozdílu
    if ./main < "$in_file" | diff -u - "$ref_file"; then
      echo "Status: OK"
    else
      echo "Status: FAIL"
    fi
    echo ""
  fi
done