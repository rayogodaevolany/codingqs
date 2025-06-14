#!/bin/bash 

# Create new file with name
if [ $# -eq 1 ]
then
    filename="$(date +%Y%m%d)_$1"
else 
    filename="$(date +%Y%m%d)_example"
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


