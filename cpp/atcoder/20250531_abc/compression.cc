#include <iostream>
#include <set>
using namespace std;

int comp(const void *a, const void *b){
    int intA = *static_cast<const int *> (a);
    int intB = *static_cast<const int *> (b);
    return intA - intB;
}

int main(){
    int N; cin >> N;
    int arr[123];
    // get the array
    for (int i = 0; i < N; i++) cin >> arr[i];

    set<int> s;
    for (int i = 0; i < N; i++){
        // insert all into set
        s.insert(arr[i]);
    }

    set<int>::iterator start = s.begin();

    int sorted[123];
    int i = 0;
    while (start != s.end()){
        sorted[i] = *start;
        i++;
        start++;
    }

    // qsort(sorted, i + 1, sizeof(int), comp);

    cout << i << endl;
    for (int m = 0; m < i; m++){
        cout << sorted[m] << " ";
    }

    return 0;
}
