#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long

ll convert(ll num, int base){
    int res = 0;
    int i = 0;
    while(num) { 
        res += (num % base) * pow(10, i); 
        i++;
        num /= base;
    }
    return res;
}

bool checkpal(ll num){
    int count = 0;
    ll tmp = num;
    while (tmp){
        tmp /= 10;
        count++;
    }
    bool pal = true;
    // check palindrome
}

void solve(){
    int a, n; cin >> a >> n;
    bool odd;
    // convert n to base a
    ll ninbasea = convert(n, a);
    if (ninbasea % 2 == 0){
        odd = false;
    } else {
        odd = true;
    }

    vector<ll> arr;
    if (odd){
        for (int i = 0; i < a; i++) arr[i] = i;
        for (int i = 0; i < a - 1; i++){
            for (int j = 0; j < (int)arr.size(); j++){
                int x = arr[j] * 10;
                x += i;
                int count = 0;
                int tmp = x;
                while (tmp){
                    tmp/=10;
                    count++;
                }
                x += i*pow(10,count);
                arr.push_back(x);
            }
        }
    } else {
        for (int i = 0; i < a; i++) arr[i] = i + (10 * i);
        for (int i = 0; i < a - 2; i++){
            for (int j = 0; j < (int)arr.size(); j++){
                int x = arr[j] * 10;
                x += i;
                int count = 0;
                int tmp = x;
                while (tmp){
                    tmp/=10;
                    count++;
                }
                x += i*pow(10,count);
                arr.push_back(x);
            }
        }
    }
    for (int i = 0; i < (int)arr.size(); i++){
        arr[i] = convert(arr[i], 10);
    }

    for (int i = 0; i < (int)arr.size(); i++){
    }
    // create all palindromes in base a
    // convert them, and store them in array
    // loop through and check if they are palindrome
}

int main(){
    solve();
    return 0;
}
