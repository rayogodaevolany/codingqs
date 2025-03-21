#include<iostream>
#include<vector>
using namespace std;

int rec(vector<int> array) {
    if (array.empty()){
        return 0;
    }
    int head = array[0];
    array.erase(array.begin());
    return head +rec(array);
}

int main() {
    vector<int> h;
    int res;
    h.push_back(3);

    h.push_back(2);
    h.push_back(5);
    h.push_back(5);


    res = rec(h);
    cout<< res;

    return 0;
}
