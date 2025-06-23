#!/bin/bash 

# Create new file with name
$filename="$(date +%Y%m%d)_abc"
mkdir -p "$filename/{1..3}"

cd "$filename"
for ((int i; i < 3; i++)); do
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

