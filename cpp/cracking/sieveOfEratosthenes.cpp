#include <iostream>
#include <vector>
using namespace std;

// a routine that creates a list from 2 to n. Primes start from 2 so 0 and 1 are unnecessary
vector<int> newList (int n) {
    vector<int> list;
    // loop from 2 to n inclusive because primes start from 2
    for (int i = 2; i <= n; i++){
        list.push_back(i);
    }
    return list;
}

// routine that remove multiples of a number from a list
vector<int> removeMultiples(vector<int> list, int n){
    vector<int> copy;
    for (int i = 0; i < list.size(); i++){
    // if it is the value add to new list 
        if (list[i] == n) {
            copy.push_back(list[i]);
        }
    //     if value modded by n is equal to zero 
        if( list[i] % n == 0){
            continue;
        }
        copy.push_back(list[i]);
    }
    return copy;
}

// routine that removes all non primes
vector<int> sieve(vector<int> list){
    int count = 0, prime = 2;
    vector <int> copy = list;
    // while the last value in the original list is not greater than the number that needs to be removed
    while(list[list.size() - 1] > prime && count < 10) {
    //     find next prime
        int prime = copy[count];
        copy = removeMultiples(copy, prime);
        count++;
    }
    return copy;

}

int main() {
    cout << "Enter a number up to which you want to find primes" << "\n";
    int SIZE;
    cin >> SIZE;
    vector<int> list = newList(SIZE);
    vector<int> primes = sieve(list);

    // print out modified list
     for (int i = 0; i < primes.size(); i++){
         cout << primes[i] << " ";
     }
    return 0;
}
