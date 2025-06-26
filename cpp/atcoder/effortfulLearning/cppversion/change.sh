#!/bin/bash
shopt -s nullglob
for file in *_*.cc; do
    if [[ $f != *_C_*.cc ]]; then
        cp -- "$f" "$f".bak
        newfile="${file%%_*}_C_${file#*_}"
        mv "$file" "$newfile"
    fi
done
