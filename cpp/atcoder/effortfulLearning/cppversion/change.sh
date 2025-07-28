#!/bin/bash
shopt -s nullglob

for file in *_C_abc*.cc; do
    # Make a backup
    cp -- "$file" "$file.bak"

    # Use pattern substitution to swap _C_ and _abc_
    # First, extract date
    datepart="${file%%_*}"
    rest="${file#*_C_abc}"  # e.g. 396_buyballs.cc
    newfile="${datepart}_abc_C_${rest}"

    mv -- "$file" "$newfile"
done
