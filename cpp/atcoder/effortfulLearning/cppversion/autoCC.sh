#!/bin/bash 

# Create new file with name
if [ $# -eq 3 ]
then
    filename="$(date +%Y%m%d)_abc_$1_$2_$3"
else 
    filename="$(date +%Y%m%d)_???_example"
fi

touch $filename.cc

cat <<EOF >>$filename.cc
#include <iostream>
using namespace std;

void solve(){
}

int main(){
    solve();
    return 0;
}
EOF

# If makefile exists change the name

FILE="./Makefile"
if [ -f "$FILE" ]; then
    echo "Makefile exists"
else
    echo "Makefile doesn't exist"
    return 1 2>/dev/null || exit 1
fi

# use sed to change the program name in the makefile
sed -i.bak "s/^program=.*/program=${filename}/" Makefile


