#! /bin/bash
#place checks
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: $0 <filename> <string to insert>";
    exit 1
fi

if [[ "$1" != *_* ]]; then
    echo "Error no _"
fi
# take input filename and then rewrite it in the new form
part1="${1%%_*}"
part2="${1#*_}"

newname="${part1}_abc${2}_${part2}"

mv $1 $newname
