#include<iostream>
#include<unordered_map>
using namespace std;

// routine that returns the mode
// input array of ints
// output int
pair<bool, int> mode(int arr[], size_t size){
    int mostFreq= 0, count = 0;
    bool flag = false;
    unordered_map<int, int> map;
    //loop through the array, counting each value in hashmap
    for(int i=0;i<size;i++){
        if(map.find(arr[i]) == map.end()){
            map.insert({arr[i], 1});
        } else {
            map[arr[i]] += 1;
        //keep count of the largest count
            if (map[arr[i]] > count){
                count = map[arr[i]];
                mostFreq = arr[i];
            }
        }
    }
    // return most frequent value
    if (count > 0)flag = true;
    return { flag, mostFreq};
}
    
int main(){
   // create array
    int arr[4] = {3, 2, 5,1};
    // call mode function to get mode
    pair<bool, int> res = mode(arr, 4);
    // print mode
    if (res.first) cout << res.second;
    else cout << "failure";


    return 0;
}
